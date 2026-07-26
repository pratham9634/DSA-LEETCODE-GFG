class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(),nums.end());

        int fp = nums[0]*nums[1]*nums[n-1];
        int sp = nums[n-1]*nums[n-2]*nums[n-3];

        return max(fp,sp);
    }
};