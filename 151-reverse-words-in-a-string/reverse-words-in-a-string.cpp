class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int n = s.length();
        string str = "";
        int i = n - 1;
        
        while (i >= 0) {
            // skip spaces
            while (i >= 0 && s[i] == ' ') i--;

            // collect word
            str = "";
            while (i >= 0 && s[i] != ' ') {
                str += s[i];
                i--;
            }
            reverse(str.begin(), str.end());

            // append to answer
            if (!str.empty()) {
                if (!ans.empty()) ans += " ";
                ans += str;
            }
        }
        
        return ans;
    }
};
