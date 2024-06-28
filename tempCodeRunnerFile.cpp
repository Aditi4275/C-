#include<bits/stdc++.h>
using namespace std;

//Knapsack Recursive

int Knapsack(int wt[],int val[],int w,int n){
    if(n == 0 || w == 0)
        return 0;
    else if(wt[n-1] <= w){
        return max(val[n-1]+Knapsack(wt,val,w-wt[n-1],n-1), Knapsack(wt,val,w,n-1));
    }
    else if(wt[n-1] > w){
        return Knapsack(wt,val,w,n-1);
    }
}

// Memorization
int static t[102][1002];
void initialise(){
    memset(t,-1,sizeof(t));
}

int knapsack(int wt[],int val[],int w,int n){
    if (n == 0 || w == 0) {
        return 0;
    }
    if(t[n][w] != -1)
        return t[n][w];
    if(wt[n-1] <= w)
        return t[n][w] = max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1), knapsack(wt,val,w,n-1));
    else if(wt[n-1] > w)
        return t[n][w] = knapsack(wt,val,w,n-1);
}

//Top down approach
int top_down(int wt[], int val[], int w, int n){
    int m[n+1][w+1];

    for(int i=0;i<n+1;i++){
        for(int j=0;j<w+1;j++){
            if(i == 0 || j == 0)
                m[i][j] = 0;
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            if(wt[i-1] <= j){
                m[i][j] = max(val[i-1]+m[i-1][j-wt[i-1]],m[i-1][j]);
            }
            else{
                m[i][j] = m[i-1][j];
            }
        }
    }
    return m[n][w];
}


int main(){
    int n = 4;
    int wt[] = {1,3,4,5};
    int val[] = {1,4,5,7};

    int w = 7;

    initialise();
    cout<<Knapsack(wt,val,w,n)<<endl;
    cout<<knapsack(wt,val,w,n)<<endl;
    cout<<top_down(wt,val,w,n)<<endl;
}