class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0)); // dp[i][j] = height of consecutive 1s above (i,j)
        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) continue;
                
                // build height
                dp[i][j] = (i == 0 ? 1 : dp[i-1][j] + 1);

                int minH = dp[i][j];
                // expand leftwards
                for(int k = j; k >= 0 && minH > 0; k--) {
                    minH = min(minH, dp[i][k]);
                    ans += minH;
                }
            }
        }
        return ans;
    }
};
