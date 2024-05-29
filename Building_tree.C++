#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class node {
    public:
        int data;
        node *left;
        node *right;

    node(int val){
        data = val;
        left = NULL;
        right =NULL;
    }
};

int search(int inorder[], int start,int end,int curr){
    for(int i=start;i<=end;i++){
        if(inorder[i] == curr)
            return i;
    }
    return -1;
}
//Building a tree from preorder and inorder tree
node *buildTree1(int preorder[],int inorder[],int start,int end){
    static int indx = 0;
    if(start > end)
        return NULL;

    int curr = preorder[indx];
    indx++;
    node *new_node = new node(curr);

    if(start == end)
        return new_node;

    int pos = search(inorder,start,end,curr);
    new_node->left = buildTree1(preorder,inorder,start,pos-1);
    new_node->right = buildTree1(preorder,inorder,pos+1,end);
    return new_node;
}
//Building a tree from postorder and inorder
node  *buildTree2(int postorder[],int inorder[],int start,int end){
    static int index = 4; //(n-1)

    if(start > end)
        return NULL;

    int curr = postorder[index];
    index--;
    node* new_node = new node(curr);
    if(start == end)
        return new_node;

    int pos = search(inorder,start,end,curr);
    new_node->right = buildTree2(postorder,inorder,pos+1,end);
    new_node->left = buildTree2(postorder,inorder,start,pos-1);
    return new_node;
}

void print(node *root){
    if( root == NULL)
        return;
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}

int main(){
    int preorder[] = {1,2,4,3,5};
    int inorder[] = {4,2,1,5,3};
    int postorder[] = {4,2,5,3,1};
    node* root1 = buildTree1(preorder,inorder,0,4);
    node* root2 = buildTree2(postorder,inorder,0,4);
    print(root1);
    cout<<endl;
    print(root2);
}