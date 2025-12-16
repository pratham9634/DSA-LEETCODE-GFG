class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int solve(int x,int y,vector<vector<int>>& g){
        if(x==n) return 0;
        if(dp[x][y]!=INT_MAX){
            return dp[x][y];
        }
        int ans = g[x][y] + solve(x+1,y,g);
        if(y-1>=0) ans = min(ans, g[x][y] + solve(x+1,y-1,g));
        if (y + 1 < n) ans = min(ans, g[x][y] + solve(x+1, y+1, g));

        return dp[x][y] = ans;
    }
    int minFallingPathSum(vector<vector<int>>& mat) {
        n = mat.size();
        int ans = 1e9;
        dp.assign(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++){
            ans = min(ans,solve(0,i,mat));
        }
        return ans;
    }
};