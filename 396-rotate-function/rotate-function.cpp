class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        
        int sum = 0;
        int sum2 = 0;

        int n = nums.size();
        for(int i=0;i<n;i++){
            sum += (i*nums[i]);
            sum2 += nums[i];
        }
        int ans = sum;
        for(int i=n-1;i>0;i--){
            sum += (sum2 -(n*nums[i]));
            ans = max(ans,sum);
        }
        return ans;
    }
};