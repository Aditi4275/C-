#include<bits/stdc++.h>
using namespace std;


class node{
    public:
    int data;
    node *next;

    node(int val){
        data = val;
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

void print(node *head){
    node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

//Middle of the linked list
int middle(node *head){
    if(head == NULL )
        return -1;
    if(head->next == NULL)
        return head->data;

    int count =0;
    node*temp =head;
    while(temp!=NULL){
        count++;
        temp =temp->next;
    }
    int half = (count)/2;
    
    temp = head;
    while(half > 0){
        temp = temp->next;
        half--;
    }

    return temp->data;

}
//--O(N)
int mid(node *head){
    if(head == NULL)
        return -1;
    node *slow = head;
    node *fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}
int main(){
    node *head = NULL;
    int n,v;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>v;
        head = add(head,v);
    }
    cout<<middle(head)<<endl;
}