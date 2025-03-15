#include<bits/stdc++.h>
using namespace std;

//Detect cycle in unidirected graph using DFS

int n,m;
vector<vector<int>>graph;
vector<int>color;
vector<int>parent;
int start_cycle, end_cycle;

bool dfs(int v, int par){
    color[v] = 1;
    for(int u: graph[v]){
        if(color[u] == 0){
            parent[u] = v;
            if(dfs(u, parent[u]))
                return true;
        }
        else if(color[u] == 1){
            start_cycle = u;
            end_cycle = u;
            return true;
        }
    }
    color[v] =2;
    return false;
}

void is_cycle(){
    color.assign(n+1, 0);
    parent.assign(n+1, -1);

    start_cycle = -1;
    for(int u=1;u<=n;u++){
        if(color[u] == 0 && dfs(u, parent[u]))
            break;
    }
    if(start_cycle == -1)
        cout<<"No cycle found\n";
    else
        cout<<"Cycle found\n";
}
signed main(){
    cin>>n>>m;
    graph.resize(n+1);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    is_cycle();
}