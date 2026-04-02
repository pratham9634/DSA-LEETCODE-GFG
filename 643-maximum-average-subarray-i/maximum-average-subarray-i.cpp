class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        
        // First window
        for(int i = 0; i < k; i++){
            sum += nums[i];
        }
        
        double ans = sum / k;
        
        // Sliding window
        for(int i = k; i < nums.size(); i++){
            sum += nums[i];
            sum -= nums[i - k];
            ans = max(ans, sum / k);
        }
        
        return ans;
    }
};