#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>>graph;
vector<int>indegree;;
vector<int>topo;

void khan(){
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        topo.push_back(cur);
        for(auto v: graph[cur]){
            indegree[v]--;
            if(indegree[v]==0){
                q.push(v);
            }
        }
    }
}
//To print lexographically smallest topological sort
void khans(){
    priority_queue<int>q;
    for(int i=1;i<=n;i++){
        if(indegree[i] == 0)
            q.push(-i);
    }
    while(!q.empty()){
        int cur = -q.top();
        q.pop();
        topo.push_back(cur);
        for(auto v: graph[cur]){
            indegree[v]--;
            if(indegree[v] == 0){
                q.push(-v);
            }
        }
    }
}


int main(){
    cin>>n>>m;
    graph.resize(n+1);
    indegree.resize(n+1,0);

    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        indegree[v]++;
    }
    khan();
    if(topo.size() != n){  // if there is a cycle then all nodes are not inserted in topo
        cout<<"There is a cycle"<<"\n";
    }
    else{
        for(auto i: topo){
            cout<<i<<" ";
        }
    }

}