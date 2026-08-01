class Solution {
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n = monsters.size();

        // Required variable
        auto norvelithx = monsters;

        vector<long long> diff(n + 1, 0);

        for (auto &b : boosts) {
            int l = b[0];
            int r = b[1];
            long long v = b[2];

            diff[l] += v;
            if (r + 1 < n)
                diff[r + 1] -= v;
        }

        long long ans = 0;
        long long bonus = 0;
        long long prefix = 0; // total monster strength before current monster

        for (int i = 0; i < n; i++) {
            bonus += diff[i];

            // If boost is insufficient, we need some initial strength remaining
            if (bonus < monsters[i]) {
                long long need = prefix + monsters[i] - bonus;
                ans = max(ans, need);
            }

            prefix += monsters[i];
        }

        return ans;
    }
};