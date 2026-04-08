class Solution {
public:
    void solve(vector<int>&curr,int idx,vector<int>& nums,vector<vector<int>>&ans){
        ans.push_back(curr);
        for(int i=idx;i<nums.size();i++){
            curr.push_back(nums[i]);
            solve(curr,i+1,nums,ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
        solve(curr,0,nums,ans);
        return ans;
    }
};