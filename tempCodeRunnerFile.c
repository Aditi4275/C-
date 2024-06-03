#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data;
    Node *next;

    Node(val){
        data = value;
        next = NULL;
    }
};

node *add(node *head, int val){
    node *temp = new node(val);
    if(head == NULL){
        head = temp;
        return head;
    }
    node *ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = temp;
    return head;
}

//Middle of the linked list
int middle(node *head){
    int count =0;
    node*temp =head;
    while(temp!=NULL){
        count++;
    }
    if(count%2 == 0)
        count = (count/2)+1;
    else
        count = count/2;
    temp = head;
    while(count > 0){
        temp =temp->next;
        count--;
    }
    return temp->data;

}

int main(){
    node *head = NULL;
    int n,v;
    for(int i=0;i<n;i++){
        cin>>v;
        head = add(head,v);
    }
    cout<<middle(haed);
}