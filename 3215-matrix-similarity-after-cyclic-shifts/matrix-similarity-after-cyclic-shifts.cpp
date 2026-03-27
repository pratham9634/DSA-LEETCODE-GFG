class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat[0].size();
        int m = mat.size();

        k = k%n;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (mat[i][j] != mat[i][(j + k) % n]) {
                    return false;
                }
            }
        }
        return true;
    }
};