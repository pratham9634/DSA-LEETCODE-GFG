class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int msum = nums[0], sum = nums[0], n = nums.size();

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                sum += nums[i];
            } else {
                msum = max(msum, sum);
                sum = nums[i];
            }
        }
        return max(msum, sum);
    }
};