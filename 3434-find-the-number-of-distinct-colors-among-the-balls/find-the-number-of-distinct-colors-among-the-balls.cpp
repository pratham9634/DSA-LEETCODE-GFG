class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& q) {
        int n = q.size();
        vector<int> ans(n, 0);
        unordered_map<int, int> mp;
        unordered_map<int, int> c;

        for (int i = 0; i < n; i++) {
            int x = q[i][0];
            int y = q[i][1];

            if (mp.find(x) != mp.end()) {
                int prev_y = mp[x];
                c[prev_y]--;
                if (c[prev_y] == 0) {
                    c.erase(prev_y);
                }
            }

            mp[x] = y;
            c[y]++;

            ans[i] = c.size();
        }
        return ans;
    }
};
