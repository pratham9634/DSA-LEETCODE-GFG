class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ms(n,nums[n-1]);
        for(int i=n-2;i>=0;i--){
            ms[i]  = max(ms[i+1],nums[i]);
        }
        int ans = 0;

        for(int i=0;i<n-k;i++){
            ans = max(ans,nums[i]+ms[i+k]);
        }
        return ans;
    }
};