class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0,ans = LONG_LONG_MIN;
        vector<long long>ksum(k,LONG_LONG_MAX/2);
        ksum[k-1] = 0;
        for(int i = 0;i<n;i++){
            sum +=nums[i];
            ans = max(ans,sum-ksum[i%k]);
            ksum[i%k] = min(ksum[i%k],sum);
        }
        
        return ans;
    }
};