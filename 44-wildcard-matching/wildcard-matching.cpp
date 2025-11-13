class Solution {
public:
    vector<vector<int>> memo;
    string s, p;

    bool solve(int i, int j) {
        int n = s.size(), m = p.size();
        if (j == m) return i == n;
        if (memo[i][j] != -1) return memo[i][j];

        bool ans = false;
        if (i == n) {
            // s is finished: remaining pattern must all be '*'
            if (p[j] == '*') ans = solve(i, j+1);
            else ans = false;
        } else {
            if (p[j] == '*') {
                // '*' matches zero chars (i, j+1) or one char and stay on '*' (i+1, j)
                ans = solve(i, j+1) || solve(i+1, j);
            } else if (p[j] == '?' || p[j] == s[i]) {
                ans = solve(i+1, j+1);
            } else {
                ans = false;
            }
        }

        memo[i][j] = ans;
        return ans;
    }

    bool isMatch(string s_, string p_) {
        s = s_; p = p_;
        int n = s.size(), m = p.size();
        memo.assign(n+1, vector<int>(m+1, -1));
        return solve(0, 0);
    }
};
