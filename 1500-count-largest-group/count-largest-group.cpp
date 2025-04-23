class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> mp;
        int ans1 = 0, ans2= 0;

        for (int i = 1; i <= n; i++) {
            int sum = 0, num = i;
            while (num> 0) {
                sum += num % 10;
                num /= 10;
            }
            mp[sum]++;
            ans1= max(ans1, mp[sum]);
        }

        for (auto it : mp) {
            if (it.second == ans1) {
                ans2++;
            }
        }
        return ans2;
    }
};