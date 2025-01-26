#include <bits/stdc++.h>
using namespace std;
#define N 3

// Possible movements of the blank tile (down, left, up, right)
int row[] = { 1, 0, -1, 0 };
int col[] = { 0, -1, 0, 1 };

// state space tree nodes
struct Node
{
    // stores the parent node of the current node
    // helps in tracing path when the answer is found
    Node* parent;

    // stores matrix
    int mat[N][N];

    // stores blank tile coordinates
    int x, y;

    // stores the number of misplaced tiles
    int cost;

    // stores the number of moves so far
    int level;

    // Constructor
    Node(int mat[N][N], int x, int y, int newX, int newY, int level, Node* parent) {
        this->parent = parent;
        memcpy(this->mat, mat, sizeof this->mat);
        swap(this->mat[x][y], this->mat[newX][newY]);
        this->cost = INT_MAX;
        this->level = level;
        this->x = newX;
        this->y = newY;
    }
};

// Function to print N x N matrix
void printMatrix(int mat[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

// Function to calculate the number of misplaced tiles
// ie. number of non-blank tiles not in their goal position
int calculateCost(int initial[N][N], int final[N][N])
{
    int count = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (initial[i][j] && initial[i][j] != final[i][j])
                count++;
    return count;
}

// Function to check if (x, y) is a valid matrix coordinate
bool isSafe(int x, int y)
{
    return (x >= 0 && x < N && y >= 0 && y < N);
}

// print path from root node to destination node
void printPath(Node* root)
{
    if (root == NULL)
        return;
    printPath(root->parent);
    printMatrix(root->mat);
    printf("\n");
}

// Comparison object to be used to order the heap
struct comp
{
    bool operator()(const Node* lhs, const Node* rhs) const
    {
        return (lhs->cost + lhs->level) > (rhs->cost + rhs->level);
    }
};

// Function to solve N*N - 1 puzzle algorithm using
// Branch and Bound. x and y are blank tile coordinates
// in initial state
void solve(int initial[N][N], int x, int y, int final[N][N])
{
    // Create a priority queue to store live nodes of
    // search tree;
    priority_queue<Node*, vector<Node*>, comp> pq;

    // create a root node and calculate its cost
    Node* root = new Node(initial, x, y, x, y, 0, NULL);
    root->cost = calculateCost(initial, final);

    // Add root to list of live nodes;
    pq.push(root);

    // Set to keep track of visited states
    set<string> visited;

    // Finds a live node with least cost,
    // add its children to list of live nodes and
    // finally deletes it from the list.
    while (!pq.empty())
    {
        // Find a live node with least estimated cost
        Node* min = pq.top();

        // The found node is deleted from the list of
        // live nodes
        pq.pop();

        // if min is an answer node
        if (min->cost == 0)
        {
            // print the path from root to destination;
            printPath(min);

            // Free memory
            delete min;
            while (!pq.empty()) {
                Node* temp = pq.top();
                pq.pop();
                delete temp;
            }
            return;
        }

        // Generate a unique key for the current state
        string key = "";
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                key += to_string(min->mat[i][j]);

        // If the state has already been visited, skip it
        if (visited.find(key) != visited.end())
            continue;

        // Mark the current state as visited
        visited.insert(key);

        // do for each child of min
        // max 4 children for a node
        for (int i = 0; i < 4; i++)
        {
            if (isSafe(min->x + row[i], min->y + col[i]))
            {
                // create a child node and calculate
                // its cost
                Node* child = new Node(min->mat, min->x, min->y,
                                       min->x + row[i], min->y + col[i],
                                       min->level + 1, min);
                child->cost = calculateCost(child->mat, final);

                // Add child to list of live nodes
                pq.push(child);
            }
        }
    }

    // If the loop ends without finding a solution
    printf("No solution exists.\n");

    // Free memory
    while (!pq.empty()) {
        Node* temp = pq.top();
        pq.pop();
        delete temp;
    }
}

int getInvCount(int arr[])
{
    int inv_count = 0;
    for (int i = 0; i < N * N - 1; i++)
        for (int j = i + 1; j < N * N; j++)
            if (arr[j] && arr[i] && arr[i] > arr[j])
                inv_count++;
    return inv_count;
}

bool isSolvable(int mat[N][N])
{
    int arr[N * N];
    int k = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            arr[k++] = mat[i][j];

    int invCount = getInvCount(arr);

    return (invCount % 2 == 0);
}

// Driver code
int main()
{
    
    int initial[N][N] =
    {
        {1, 2, 3},
        {0, 7, 6},
        {4, 5, 8}
    };

    
    int final[N][N] =
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}
    };

    
    int x = 1, y = 0;

    if (!isSolvable(initial)) {
        printf("The puzzle is not solvable.\n");
        return 0;
    }

    solve(initial, x, y, final);

    return 0;
}