class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {

        int n=nums.size();
        int ans=0;

        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }

        for(auto &[key,value]:mp){
            if(value >= n/2){
                ans=key;
                return ans;
            }

        }

        return ans;
        
    }
};