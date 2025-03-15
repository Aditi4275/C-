//Topological sort 
#include<bits/stdc++.h>
using namespace std;


vector<vector<int>>g;
vector<int>vis;
vector<int>topo;

void dfs(int node){
    vis[node] = 1;

    for(auto u: g[node]){
        if(!vis[u])
            dfs(u);
    }
    topo.push_back(node);
}
//RECURSIVE CODE
int dp[100100];
int rec(int node){  //Longest path starting at node
    if(dp[node] != -1) return dp[node];
    int ans = 1;
    for(auto v:g[node]){
        ans = max(ans, 1+rec(v));
    }
    return dp[node] = ans;
}

signed main(){
    int n,m;
    cin>>n>>m;
    
    g.resize(n+1);
    vis.assign(n+1, 0);

    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
    }
    //RECURSIVE CODE (longest path starting at node)
    memset(dp,-1,sizeof(dp)); 
    int ans = 0;
    for(int i=1;i<=n;i++){
        ans = max(ans, rec(i));
    }
    cout<<ans<<endl;

    //TOPOLOGICAL ORDER (provides the order in which the nodes should be visited)
    for(int i=1;i<=n;i++){
        if(!vis[i])
            dfs(i);
    }
    
    reverse(topo.begin(), topo.end());
    for(auto v: topo){
        cout<<v<<" ";
    }
    
    //ITERATIVE APPROACH (Longest path starting at node)
    
    int final = 0;
    for(auto node: topo){
        int ans = 1;
        for(auto v:g[node]){
            ans = max(ans, 1+dp[v]);
        }
        dp[node] =  ans;
        final = max(final,dp[node]);
    }
    cout<<final<<"\n";
}