class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        
        int l = 0, r = n - 1;
        int pos = n - 1;
        
        while (l <= r) {
            if (abs(nums[l]) > abs(nums[r])) {
                res[pos--] = nums[l] * nums[l];
                l++;
            } else {
                res[pos--] = nums[r] * nums[r];
                r--;
            }
        }
        
        return res;
    }
};