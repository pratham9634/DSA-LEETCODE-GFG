class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        for(int j = 1;j<n;j++){
            for(int i=0;i<n-j;i++){
                nums[i]+=nums[i+1];
                nums[i]%=10;
            }
        }
        return nums[0];
    }
};