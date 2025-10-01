class Solution {
public:
    int n ;
    vector<vector<int>> ans;

    void solve(int idx,vector<int>&nums){
        if(idx==n){
            ans.push_back(nums);
            return;
        }
        unordered_set<int> st;
        for(int i=idx;i<n;i++){
            if(st.find(nums[i])!=st.end()) continue;

            st.insert(nums[i]);
            swap(nums[i],nums[idx]);
            solve(idx+1,nums);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        ans.clear();  
        n = nums.size();
        
        solve(0,nums);

        return ans;
    }
};