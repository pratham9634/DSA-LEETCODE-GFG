class Solution {
public:
    int minCost(string c, vector<int>& nt) {
        int ans = 0;
        int sum = 0, mx = 0;

        for (int i = 0; i < c.size(); i++) {
            // If current balloon continues the same color group
            if (i > 0 && c[i] != c[i-1]) {
                ans += sum - mx; // remove all but one in previous group
                sum = 0;
                mx = 0;
            }

            sum += nt[i];
            mx = max(mx, nt[i]);
        }

        // Process last group
        ans += sum - mx;
        return ans;
    }
};
