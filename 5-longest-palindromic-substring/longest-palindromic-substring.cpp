class Solution {
public:
    string helper(int idx, string &s) {
        int n = s.length();
        int i = idx - 1, j = idx + 1;
        while (i >= 0 && j < n && s[i] == s[j]) {
            i--;
            j++;
        }
        return s.substr(i + 1, j - (i + 1));
    }

    string helper2(int idx, string &s) {
        int n = s.length();
        int i = idx, j = idx + 1;
        while (i >= 0 && j < n && s[i] == s[j]) {
            i--;
            j++;
        }
        return s.substr(i + 1, j - (i + 1));
    }

    string longestPalindrome(string s) {
        int n = s.length();
        string ans = "";
        for (int i = 0; i < n; i++) {
            string p1 = helper(i, s);   
            string p2 = helper2(i, s); 
            if (p1.length() > ans.length()) ans = p1;
            if (p2.length() > ans.length()) ans = p2;
        }
        return ans;
    }
};
