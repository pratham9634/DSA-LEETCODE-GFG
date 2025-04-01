class Solution {
public:
        long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; --i) {
            long long points = questions[i][0];
            int brainpower = questions[i][1];
            int nextIndex = i + brainpower + 1;

            long long takePoints = points + (nextIndex < n ? dp[nextIndex] : 0);
            long long skipPoints = dp[i + 1];

            dp[i] = max(takePoints, skipPoints);
        }
        return dp[0];
    }
};