class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        generateSubsets(subset, 0, nums, result);
        return result;
    }

private:
    void generateSubsets(vector<int>& subset, int index, vector<int>& nums, vector<vector<int>>& result) {
        result.push_back(subset);
        for (int i = index; i < nums.size(); i++) {
            subset.push_back(nums[i]);
            generateSubsets(subset, i + 1, nums, result);
            subset.pop_back();
        }
    }
};