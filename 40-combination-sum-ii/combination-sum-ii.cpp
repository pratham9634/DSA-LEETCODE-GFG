class Solution {
public:
    void solve(vector<int>& curr, int idx, vector<int>& nums, vector<vector<int>>& ans, int tg) {
        
        if (tg == 0) {
            ans.push_back(curr);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {

            if (i > idx && nums[i] == nums[i - 1]) continue;

    
            if (nums[i] > tg) break;

            curr.push_back(nums[i]);
            solve(curr, i + 1, nums, ans, tg - nums[i]); 
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> ans;
        vector<int> curr;

        solve(curr, 0, candidates, ans, target);
        return ans;
    }
};