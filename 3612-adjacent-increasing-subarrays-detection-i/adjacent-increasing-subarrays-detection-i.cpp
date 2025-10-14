class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2 * k) return false; // we need two non-overlapping subarrays of size k

        vector<bool> inc(n, false);

        // Mark increasing subarrays of length k
        for (int i = 0; i + k <= n; i++) {
            bool flag = true;
            for (int j = i; j < i + k - 1; j++) {
                if (nums[j] >= nums[j + 1]) {
                    flag = false;
                    break;
                }
            }
            inc[i] = flag;
        }

        // Check if there are two non-overlapping increasing subarrays
        for (int i = 0; i + 2 * k <= n; i++) {
            if (inc[i] && inc[i + k]) return true;
        }

        return false;
    }
};
