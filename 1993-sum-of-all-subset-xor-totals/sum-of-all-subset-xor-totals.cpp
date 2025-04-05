class Solution {
public:
    void helper(vector<int>& nums,int &ans,int curr,int i){
        if(i==nums.size()){
            ans+=curr;
            return;
        }
        helper(nums,ans,curr^nums[i],i+1);
        helper(nums,ans,curr,i+1);
    }
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        helper(nums,ans,0,0);
        return ans;
    }
};