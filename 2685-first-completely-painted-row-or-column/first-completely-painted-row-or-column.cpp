class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int r = mat.size(), c = mat[0].size();
        unordered_map<int, pair<int, int>> mp;
        vector<int> rowCount(r, c), colCount(c, r);

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                mp[mat[i][j]] = {i,j};
            }
        }

        for (int idx = 0; idx < arr.size(); ++idx) {
            int val = arr[idx];
            auto [row, col] = mp[val];

            if (--rowCount[row] == 0 || --colCount[col] == 0) {
                return idx;
            }
        }

        return -1;
    }
};