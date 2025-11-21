class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        unordered_map<char, pair<int, int>> mp;
        for (char c = 'a'; c <= 'z'; c++) {
            mp[c] = {-1, -1};
        }

        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (mp[c].first == -1) {
                mp[c].first = i;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            char c = s[i];
            if (mp[c].second == -1) {
                mp[c].second = i;
            }
        }

        int ans = 0;
        for (const auto& p : mp) {
            char c = p.first;
            int first = p.second.first;
            int last = p.second.second;

            if (first != -1 && last != -1 && first < last) {
                unordered_set<char> st;
                for (int i = first + 1; i < last; i++) {
                    st.insert(s[i]);
                }
                ans += st.size();
            }
        }
        return ans;
    }
};