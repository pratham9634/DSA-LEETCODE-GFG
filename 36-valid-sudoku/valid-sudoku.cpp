class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& m) {
        int n = 9;

        for (int i = 0; i < n; i++) {
            unordered_map<char, int> mp;
            for (int j = 0; j < n; j++) {
                if (m[i][j] != '.') {
                    if (++mp[m[i][j]] > 1) return false; 
                }
            }
        }

        for (int i = 0; i < n; i++) {
            unordered_map<char, int> mp;
            for (int j = 0; j < n; j++) {
                if (m[j][i] != '.') {
                    if (++mp[m[j][i]] > 1) return false;
                }
            }
        }

        for (int row = 0; row < 9; row += 3) {
            for (int col = 0; col < 9; col += 3) {
                unordered_map<char, int> mp;
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        char current = m[row + i][col + j];
                        if (current != '.') {
                            if (++mp[current] > 1) return false;
                        }
                    }
                }
            }
        }

        return true; 
    }
};