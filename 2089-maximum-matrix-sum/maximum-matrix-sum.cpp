class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& mat) {
        long long ans = 0;
        int minnum = INT_MAX;
        int ncount = 0;
        
        for (auto& row : mat) {
            for (int x : row) {
                minnum = min(minnum, abs(x));
                if (x < 0) {
                    ans -= x;
                    ncount++;
                } else {
                    ans += x;
                }
            }
        }
        return ans - 2 * (ncount % 2) * minnum;
    }
};