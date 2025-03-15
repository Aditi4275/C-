#include<bits/stdc++.h>
using namespace std;

//To check wether the graph is bipartite or not
int n,m;
vector<vector<int>>graph;
vector<int>parent;

bool dfs(int u, int x){   //x->color(0,1)
    if(parent[u] != -1)   //if parent is already assigned
        return (parent[u] == x);  //if the color is same as parent color
    parent[u] = x;
    for(auto v: graph[u]){
        if(!dfs(v, 1-x))   //to check bipartite
            return false;
    }
    return true;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    graph.resize(n+1);
    parent.assign(n+1, -1);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i=1;i<=n;i++){
        if(parent[i] == -1 && !dfs(i, 0)){
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
}