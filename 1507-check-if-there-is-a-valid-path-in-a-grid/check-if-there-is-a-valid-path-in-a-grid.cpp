class Solution {
public:
    int m,n;
    unordered_map<int, vector<vector<int>>> mp = {
        {1, {{0, -1}, {0, 1}}},
        {2, {{-1, 0}, {1, 0}}},
        {3, {{0, -1}, {1, 0}}},
        {4, {{0, 1}, {1, 0}}},
        {5, {{0, -1}, {-1, 0}}},
        {6, {{-1, 0}, {0, 1}}}
    };
    bool solve(vector<vector<int>>&grid,int i,int j,vector<vector<bool>>&vis){
        if(i==m-1 && j==n-1) return true;;
        vis[i][j] = true;

        for(auto& dir : mp[grid[i][j]]){
            int ni = i + dir[0];
            int nj = j + dir[1];

            if(ni<0 || ni>=m || nj<0||nj>=n||vis[ni][nj]) continue;

            for(auto& bdir : mp[grid[ni][nj]]){
                if(ni+bdir[0] == i && nj+bdir[1]==j){
                    if(solve(grid,ni,nj,vis)) return true;
                }
            }
        }
        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
         m = grid.size();
        n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        return solve(grid, 0, 0, visited);
    }
};