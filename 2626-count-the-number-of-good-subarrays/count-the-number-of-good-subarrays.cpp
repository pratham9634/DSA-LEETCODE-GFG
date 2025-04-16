class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long int ans = 0,x=0;
        int i=0,j=0,n=nums.size();
        unordered_map<int,int> mp;
        while(i<n){
            mp[nums[i]]++;
            x += (mp[nums[i]]-1);
            while(x >= k){
                ans += (n-i);
                mp[nums[j]]--;
                x -= mp[nums[j]];
                j++;
            }
            i++;
        }
        return ans;
    }
};