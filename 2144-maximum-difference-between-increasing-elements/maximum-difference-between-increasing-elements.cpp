class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int>vec(n,0);
        vec[n-1]=nums[n-1];
        int ans = -1;
        for(int i=n-2;i>=0;i--){
            vec[i]=max(nums[i],vec[i+1]);
        }
        for(int i=0;i<n-1;i++){
            if(vec[i]>nums[i])ans = max(ans,vec[i]-nums[i]);
        }
        return ans;
    }
};