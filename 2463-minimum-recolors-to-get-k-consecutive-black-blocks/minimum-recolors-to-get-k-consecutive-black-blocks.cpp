class Solution {
public:
    int minimumRecolors(string s, int k) {
        int n = s.length();
        int count = 0, ans = INT_MAX;

        for (int i = 0; i < k; i++) {
            if (s[i] == 'W') count++;
        }
        ans = count;

        for (int i = k; i < n; i++) {
            if (s[i] == 'W') count++;
            if (s[i - k] == 'W') count--;
            ans = min(ans, count);
        }

        return ans;
    }
};
