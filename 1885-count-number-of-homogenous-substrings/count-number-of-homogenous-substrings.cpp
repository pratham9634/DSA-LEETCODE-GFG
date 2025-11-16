class Solution {
public:
    int countHomogenous(string s) {
        int cnt = 0, total = 0, mod = 1e9 + 7;
        char prev = '-1';
        for (char ch : s) {
            if (ch == prev||prev=='-1') {
                prev = ch;
                cnt++;
            } else {
                prev = ch;
                cnt = 1;
            }
            total = (total + cnt) % mod;
        }
        return total;
    }
};