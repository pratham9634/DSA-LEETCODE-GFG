class Solution {
public:
    int maximumEnergy(vector<int>& e, int k) {
        int n = e.size();
        int ans = INT_MIN;
        vector<int> dp(n,0);
        for(int i=n-1;i>=0;i--){
            dp[i] = e[i] + ((i+k<n)?dp[i+k]:0);
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};