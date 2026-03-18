class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>psum(m,vector<int>(n,0));
        int ans = 0;


        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                psum[i][j] = grid[i][j];
                psum[i][j] += j>0?psum[i][j-1]:0;
            }
        }
        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++){
                psum[i][j] += i>0?psum[i-1][j]:0;
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(psum[i][j]<=k) ans++;
            }
        }

        return ans;
    }
};