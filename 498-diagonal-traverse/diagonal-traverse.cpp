class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> ans;
        ans.reserve(m * n);

        for (int d = 0; d < m + n - 1; d++) {
            int r, c;

            // Determine the starting row/col of this diagonal
            if (d % 2 == 0) { 
                // going up
                r = (d < m) ? d : m - 1;
                c = d - r;
                while (r >= 0 && c < n) {
                    ans.push_back(mat[r][c]);
                    r--, c++;
                }
            } else { 
                // going down
                c = (d < n) ? d : n - 1;
                r = d - c;
                while (c >= 0 && r < m) {
                    ans.push_back(mat[r][c]);
                    r++, c--;
                }
            }
        }
        return ans;
    }
};
