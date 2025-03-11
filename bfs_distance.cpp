#include<bits/stdc++.h>
using namespace std;

using state = pair<int,int>;

int n,m;
vector<vector<char>>arr;
vector<vector<int>>dist;
vector<vector<int>>vis;
vector<vector<state>>parent;

#define F first
#define S second

vector<state>path;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

bool isValid(int x, int y){
    if( x<0 || x>=n || y<0 || y>=m || arr[x][y] == '#') return false;
    return true;
}

vector<state> neighbours(state node){
    vector<state>n;
    for(int i=0;i<4;i++){
        int x = node.F + dx[i];
        int y = node.S + dy[i];
        if(isValid(x,y))
            n.push_back({x,y});
    }
    return n;
}

void bfs(state node){
    vis.assign(n, vector<int>(m,0));
    dist.assign(n, vector<int>(m,1e9));
    parent.assign(n,vector<state>(m,{-1,-1}));

    queue<state>q;
    vis[node.F][node.S] = 1;
    dist[node.F][node.S] = 0;
    parent[node.F][node.S] = {-1, -1};

    q.push(node);
    
    while(!q.empty()){
        state cur = q.front();
        q.pop();
        for(auto v: neighbours(cur)){
            if(!vis[v.F][v.S]){
                vis[v.F][v.S] = 1;
                dist[v.F][v.S] = dist[cur.F][cur.S]+1;
                parent[v.F][v.S] = cur;
                q.push(v);
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); 

    cin>>n>>m;
    arr.resize(n);

    state start, end;
    for(int i=0;i<n;i++){
        arr[i].resize(m);
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            if(arr[i][j] == 'S')
                start = {i,j};
            else if(arr[i][j] == 'F')
                end = {i,j};
        }
    }
    bfs(start);
    if(!vis[end.F][end.S])
        cout<<"Finish not reachable\n";
    else
        cout<<dist[end.F][end.S]<<"\n";

   
    state cur = end;
    while(cur != make_pair(-1,-1)){
        path.push_back(cur);
        cur = parent[cur.F][cur.S];
    }
    reverse(path.begin(), path.end());

    for(auto v: path){
        cout<<v.F<<" "<<v.S<<"\n";
    }
    
}