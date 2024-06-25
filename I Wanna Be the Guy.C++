#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n+1] = {0};
    int x,y;
    cin>>x;
    int arr_x[x+1];
    for(int i=1;i<=x;i++){
        cin>>arr_x[i];
        arr[arr_x[i]]++;
    }
    cin>>y;
    int arr_y[y+1];
    for(int i=1;i<=y;i++){
        cin>>arr_y[i];
        arr[arr_y[i]]++;
    }
    int flag =0;
    for(int i=1;i<=n;i++){
        if(arr[i] == 0){
            flag = 1;
            break;
        }
    }
    if(flag == 0)
        cout<<"I become the guy."<<endl;
    else
        cout<<"Oh, my keyboard!"<<endl;
}