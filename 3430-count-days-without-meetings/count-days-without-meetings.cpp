class Solution {
public:
    int countDays(int days, vector<vector<int>>& m) {
        if (m.empty()) return days;

        sort(m.begin(), m.end());

        vector<vector<int>> merged;
        for (auto& interval : m) {
            if (!merged.empty() && merged.back()[1] >= interval[0] - 1) {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            } else {
                merged.push_back(interval);
            }
        }

        int ans = 0;
        if (merged[0][0] > 1) ans += merged[0][0] - 1;

        for (int i = 0; i < merged.size() - 1; i++) {
            ans += merged[i + 1][0] - merged[i][1] - 1;
        }

        if (merged.back()[1] < days) ans += days - merged.back()[1];

        return ans;
    }
};
