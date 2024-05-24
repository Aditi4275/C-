#include<bits/stdc++.h>
using namespace std;

//Pascals triangle
//Variation 1: Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle.


int nCr(int n,int r){
    long long res = 1;
    for(int i=0;i<r;i++){
        res = res*(n-i);
        res = res/(i+1);
    }
    return res;
}

//Variation 2: Given the row number n. Print the n-th row of Pascal’s triangle.


void pascal_row(int row){
    for(int i=1;i<=row;i++){
        cout<<nCr(row-1,i-1)<<" ";
    }
    cout<<endl;
}

//Variation 3: Given the number of rows n. Print the first n rows of Pascal’s triangle.

void pascal_triangle(int n){
    for(int i=1;i<=n;i++){
        pascal_row(i);
    }
}
// Optimized Pascal triangle
vector<int> generate_rows(int n){
    long long res =1;
    vector<int>ans;
    ans.push_back(1);

    for(int i=1;i<n;i++){
        res = res*(n-i);
        res = res/i;
        ans.push_back(res);
    }
    return ans;
}

vector<vector<int>> pascal_tri(int n){
    vector<vector<int>> ans;
    for(int i=1;i<=n;i++){
        ans.push_back(generate_rows(i));
    }
    return ans;
}

int main(){
    /*
    int r,c;
    cin>>r>>c;
    int k =nCr(r-1,c-1);
    cout<<k;
    
   int row;
   cin>>row;
   pascal_row(row);
   */
  int n;
  cin>>n;
  pascal_triangle(n);

  vector<vector<int>> ans = pascal_tri(n);
  for(auto it :ans){
    for(auto ele :it){
        cout<<ele<<" ";
    }
    cout<<endl;
  }

}