class Solution {
public:
    int m, n;
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    bool dfs(vector<vector<char>>& grid, int i, int j,vector<vector<bool>>& vis,int pi, int pj, char ch){

        vis[i][j] = true;
        for(auto &d : dir){
            int ni = i+d[0];
            int nj = j+d[1];

            if(ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
            if(grid[ni][nj] != ch) continue;

            if(!vis[ni][nj]) {
                if(dfs(grid, ni, nj, vis, i, j, ch)) return true;
            }
            else if(ni != pi || nj != pj) {
                return true;
            }

        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j]) {
                    if(dfs(grid, i, j, vis, -1, -1, grid[i][j]))
                        return true;
                }   
            }
        }
        return false;
    }
};