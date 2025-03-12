//Max area of an island

#include<bits/stdc++.h>
using namespace std;


//First Approach
vector<vector<int>>vis;
int max_area = 0;
void dfs(int r, int c, vector<vector<int>>&grid, int &sz){
    vis[r][c] = 1;
    sz++;
    int n = grid.size();
    int m = grid[0].size();

    int dx[] = {1,0,-1,0};
    int dy[] = {0,1,0,-1};

    for(int i=0;i<4;i++){
        int x = r + dx[i];
        int y = c + dy[i];
        if(x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && grid[x][y] ==1)
            dfs(x,y,grid,sz);
    }

}

int maxArea(vector<vector<int>>&grid){
    int n = grid.size();
    int m = grid[0].size();

    vis.assign(n, vector<int>(m,0));
    max_area = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && grid[i][j] == 1){
                int sz = 0;
                dfs(i,j,grid,sz);
                max_area = max(sz,max_area);
            }
        }
    }
    return max_area;
}

//Second Approach
class Solution{
    public:
        void dfs(int r, int c, vector<vector<int>>&grid, int &sz){
            if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0)
                return 0;
            grid[r][c] = 0;
            return 1 + dfs(r-1, c, grid, sz) + dfs(r+1, c, grid, sz) + dfs(r, c-1, grid, sz) + dfs(r, c+1, grid, sz); 
        }
    
        int maxAreaOfIslands(vector<vector<int>>&grid){
            int n = grid.size();
            int m = grid[0].size();
            int max_area = 0;
    
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j] == 1){
                        int count = dfs(i,j,grid,count);
                        max_area = max(max_area, count);
                    }
                }
            }
            return max_area;
        }
    };


int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> grid(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    cout<<maxArea(grid)<<"\n";
    return 0;
}