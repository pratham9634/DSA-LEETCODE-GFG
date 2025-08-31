class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size(),ans=0,prefix=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0)nums[i]=0;
            else nums[i]=1;
        }
        unordered_map<int,int> mp;
        mp[0] = 1;
        for(int i=0;i<n;i++){
            prefix += nums[i];
            int rem = prefix-k; 
            if(mp.find(rem)!=mp.end()){
                ans+=mp[rem];
            }
            mp[prefix]++;
        }
        return ans;
    }
};