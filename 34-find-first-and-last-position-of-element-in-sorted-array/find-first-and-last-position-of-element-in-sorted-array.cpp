class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return {-1, -1};
        int l = 0, h = n - 1, first = -1, last = -1;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (nums[m] >= target) {
                h = m - 1;
            } else {
                l = m + 1;
            }
            if (nums[m] == target) first = m;
        }

        l = 0, h = n - 1;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (nums[m] <= target) {
                l = m + 1;
            } else {
                h = m - 1;
            }
            if (nums[m] == target) last = m;
        }

        return {first, last};
    }
};
