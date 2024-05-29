#include<bits/stdc++.h>
using namespace std;

class node {
    public:
    int data;
    int *left;
    int *right;

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
node *buildTree(int preorder[],int inorder[],int start,int end){
    static int indx = 0;
    if(start > end)
        return NULL;

    int curr = preorder[indx];
    indx++;
    node *new_node = new node(curr);

    if(start == end)
        return new_node;
        
    int pos = search(inorder,start,end,curr);
    new_node->left = buildTree(preorder,inorder,start,pos-1);
    new_node->right = buildTree(preorder,inorder,pos+1,end);
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
    node* root = buildTree(preorder,inorder,0,4);
    print(root);
}