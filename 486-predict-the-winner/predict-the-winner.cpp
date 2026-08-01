class Solution {
public:
    int solve(int i,int j,vector<int>&nums){
        if(i>j) return 0;
        if(i==j) return nums[j];

        int t1 = nums[i] + min(solve(i+2,j,nums),solve(i+1,j-1,nums));
        int t2 = nums[j] + min(solve(i,j-2,nums),solve(i+1,j-1,nums));

        return max(t1,t2);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int total =  accumulate(begin(nums),end(nums),0);

        int p1 = solve(0,n-1,nums);
        int p2 = total - p1;
        return p1>=p2;
    }
};