class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();

        int l = 0, h = n * m - 1;  // fix upper bound
        while (l <= h) {
            int mid = l + (h - l) / 2;
            int row = mid / m;     // fix row index
            int col = mid % m;     // fix col index

            if (mat[row][col] == target) return true;
            else if (mat[row][col] < target) l = mid + 1;
            else h = mid - 1;
        }
        return false;
    }
};
