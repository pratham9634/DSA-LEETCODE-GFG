class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(nums.begin(),nums.end());
        for (int i = 0; i < n; ++i) {
            int steps = nums[i];
            int Index;

            if (steps > 0) {
                Index = (i + steps) % n;
            } else if (steps < 0) {
                Index = (i + steps%n + n) % n;
            }else Index = i;
            result[i] = nums[Index];
        }
        return result;
    }
};