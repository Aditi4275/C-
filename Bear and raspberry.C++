#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,c;
    cin>>n>>c;
    list<int>l;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        l.push_back(val);
    }
    int min_ele = *min_element(l.begin(),l.end());
    if (c == 0){
        cout<<0<<endl;
        return 0;
    }
    for(auto it=l.begin();it != l.end();it++){
        if (*it == min_ele) {
            if (it != l.begin()) {
                auto prev_it = prev(it);
                cout << *prev_it - *it - c << endl;
            }
            break;
        }
    }

}