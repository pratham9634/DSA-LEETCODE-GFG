class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for (const string& s : words) {
            if (s.substr(0, pref.length()) == pref) {
                ans++;
            }
        }
        return ans;
    }
};