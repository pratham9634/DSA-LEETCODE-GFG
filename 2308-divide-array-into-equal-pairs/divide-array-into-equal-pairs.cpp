class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int>mp;

        for(int c : nums){
            mp[c]++;
        }
        for(auto& p : mp){
            if(p.second%2==1) return false;
        }
        return true;
    }
};