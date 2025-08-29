class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int l = 0, h = m - 1;

        while (l <= h) {
            int mid = (l + h) / 2;

            // Find row with max element in column mid
            int mr = 0;
            for (int i = 0; i < n; i++) {
                if (mat[i][mid] > mat[mr][mid]) mr = i;
            }

            int ce = mat[mr][mid];
            int le = (mid == 0) ? -1 : mat[mr][mid - 1];
            int re = (mid == m - 1) ? -1 : mat[mr][mid + 1];

            if (ce > le && ce > re) {
                return {mr, mid}; // found peak
            } else if (ce < le) {
                h = mid - 1; // move left
            } else {
                l = mid + 1; // move right
            }
        }
        return {-1, -1};
    }
};
