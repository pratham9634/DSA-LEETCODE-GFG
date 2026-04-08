class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        const int mod = 1e9 + 7;

        for (auto &query : q) {
            int l = query[0];
            int r = query[1];
            int k = query[2];
            int v = query[3];

            for (int j = l; j <= r; j += k) {
                nums[j] = (1LL * nums[j] * v) % mod;
            }
        }

        int ans = 0;
        for (int num : nums) {
            ans ^= num;
        }

        return ans;
    }
};