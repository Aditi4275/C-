#include<bits/stdc++.h>
using namespace std;

int N = 100010;

vector<int>graph[N];
vector<int>visited(N, 0);
int sz[N];   // Size of each compenent
int id[N];   //to which component the node belongs
int cur_id = 1; //first ele belongs to 1st component 

void dfs(int cur){
    if(visited[cur]) return ;
    visited[cur] = 1;
    id[cur] = cur_id;
    sz[cur_id]++;

    for(auto u: graph[cur]){
        if(!visited[u]){
            dfs(u);
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,q;
    cin>>n>>m>>q;
    while(m--){              //Construct an adjacency list
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    for(auto i :graph){
        if(!visited[i]){
            dfs(i);
            cur_id++;
        }
    }
    while(q--){
        int t;
        cin>>t;
        if(t == 1){
            int x;
            cin>>x;
            cout<<sz[id[x]<<"\n"];   //Size of the component to which x belongs
        }
        else{
            int x,y;
            cin>>x>>y;
            if(id[x] == id[y]) 
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
    }



}