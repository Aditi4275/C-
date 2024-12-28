#include<bits/stdc++.h>
using namespace std;
// 3 repitions
typedef long long int ll;
const ll mod = 1e9+7;

int single_element(vector<int>&arr){
    int n = arr.size();
    int ans = 0;

    for(int i=0;i<32;i++){
        int sum = 0;
        for(int j=0;j<n;j++){
            sum += (arr[j] & (1 << i));
        }
        if(sum % 3)
            ans |= (1 << i);
    }
    return ans;
}

signed main(){
    vector<int>arr = {23, 5, 23, 4, 23, 4, 5, 3, 5, 4};
    cout<<single_element(arr)<<endl;
}