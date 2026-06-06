class Solution {
public:

    vector<int> leftRightDifference(vector<int>& nums) {
        int leftSum = 0; 
        int rightSum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> differences;

        for (int num : nums) {
            rightSum -= num; 
            differences.push_back(abs(leftSum - rightSum));
            leftSum += num;
        }
      
        return differences; 
    }
};