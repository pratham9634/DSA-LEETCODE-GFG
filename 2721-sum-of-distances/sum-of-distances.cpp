class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<long long>> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<long long> ans(n, 0);

        for (auto &it : mp) {
            vector<long long> &vec = it.second;
            int m = vec.size();

            vector<long long> prefix(m, 0);
            prefix[0] = vec[0];

            for (int i = 1; i < m; i++) {
                prefix[i] = prefix[i - 1] + vec[i];
            }

            for (int i = 0; i < m; i++) {
                long long left = 0, right = 0;

                if (i > 0) {
                    left = (long long)i * vec[i] - prefix[i - 1];
                }

                if (i < m - 1) {
                    right = (prefix[m - 1] - prefix[i]) - (long long)(m - i - 1) * vec[i];
                }

                ans[vec[i]] = left + right;
            }
        }

        return ans;
    }
};