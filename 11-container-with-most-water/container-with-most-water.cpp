class Solution {
public:
    long long maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        long long ans = 0;
        while (left < right) {
            int hi = min(height[left], height[right]);
            long long sum = hi * (right - left);
            ans = max(ans, sum);
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return ans;
    }
};