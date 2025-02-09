class Solution {
public:
    long long countBadPairs(vector<int>& nums) {

        unordered_map<int,int>mp;
        int n=nums.size();
        long long ans=0;
        int i=0;
        while(i<nums.size())
        {
            mp[i-nums[i]]++;
            i++;
        }
        i=0;
        while(i<nums.size())
        {
            mp[i-nums[i]]--;
            ans+=(n-(i+1+mp[i-nums[i]]));
            i++;
        }

        return ans;
        
    }
};