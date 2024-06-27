#include<bits/stdc++.h>
using namespace std;

/*
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

int main(){
    int n,k;
    cin>>n>>k;
    node *even = NULL;
    node *odd = NULL;
    for(int i=1;i<=n;i++){
        if(i%2 == 0){
            even = add(even,i);
        }
        else{
            odd = add(odd,i);
        }
    }
    node *end = odd;
    while(end->next != NULL){
        end = end->next;
    }
    end->next = even;
    node *val=odd;
    while(k > 1){
        val = val->next;
        k--;
    }
    cout<<val->data<<endl;
}
*/

int main(){
    int n,k;
    cin>>n>>k;
    int half = ceil(n/2.0);
   
    int val;
    if(k <= half){
        val = 1+(k-1)*2;
    }
    else{
        val = 2+(k-half-1)*2;
    }
    cout<<val<<endl;
}