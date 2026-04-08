class Solution {
public:
    void solve(vector<int>&curr,int idx,vector<int>&nums,vector<vector<int>>&ans,int tg){
        if(tg<0) return;
        if(tg==0){
            ans.push_back(curr);
            return;
        }
        for(int i=idx;i<nums.size();i++){

            curr.push_back(nums[i]);
            solve(curr,i,nums,ans,tg-nums[i]);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>curr;
        solve(curr,0,candidates,ans,target);
        return ans;
    }
};