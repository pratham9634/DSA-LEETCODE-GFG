class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        mp[0] = 1; // empty prefix sum
        
        int prefix = 0, ans = 0;
        for(int i=0;i<n;i++){
            prefix += nums[i];
            int rem = prefix - k;
            if(mp.find(rem)!=mp.end()){
                ans += mp[rem];  // count subarrays ending at i
            }
            mp[prefix]++; // store current prefix
        }
        return ans;
    }
};
