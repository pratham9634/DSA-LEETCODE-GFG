class Solution {
public:
    int digitSum(int n) {
        int ans = 0;
        while (n > 0) {
            ans += n % 10;
            n /= 10;
        }
        return ans;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int, pair<int, int>> mp;
        int ans = -1;

        for (int x : nums) {
            int sumDigits = digitSum(x);
            if (mp.find(sumDigits) != mp.end()) {
                int max1 = mp[sumDigits].first;
                int max2 = mp[sumDigits].second;
                
                if (x > max1) {
                    max2 = max1;
                    max1 = x;
                } else if (x > max2) {
                    max2 = x;
                }

                mp[sumDigits] = {max1, max2};

                if (max2 != -1) {
                    ans = max(ans, max1 + max2);
                }
            } else {
                mp[sumDigits] = {x, -1};
            }
        }
        return ans;
    }
};
