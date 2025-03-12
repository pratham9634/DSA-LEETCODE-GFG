class Solution {
public:
    int binarySearch(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, pos = nums.size();
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                pos = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return pos;
    }

    int maximumCount(vector<int>& nums) {
        int negCount = binarySearch(nums, 0);
        int posCount = nums.size() - binarySearch(nums, 1);
        return max(negCount, posCount);
    }
};
