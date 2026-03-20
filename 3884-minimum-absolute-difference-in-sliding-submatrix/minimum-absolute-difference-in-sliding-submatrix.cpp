class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int nm = m-k+1;
        int nc = n-k+1;
        vector<vector<int>>ans(nm,vector<int>(nc,0));

        for(int i=0;i<nm;i++){
            for(int j=0;j<nc;j++){
                 vector<int> kgrid;
                for(int x=i;x<i+k;x++){
                    for(int y=j;y<j+k;y++){
                         kgrid.push_back(grid[x][y]);
                    }
                }

                 int kmin = INT_MAX;
                sort(kgrid.begin(), kgrid.end());
                for (int t = 1; t < kgrid.size(); t++) {
                    if (kgrid[t] == kgrid[t - 1]) {
                        continue;
                    }
                    kmin = min(kmin, kgrid[t] - kgrid[t - 1]);
                }
                if (kmin != INT_MAX) {
                    ans[i][j] = kmin;
                }
            }
        }
        return ans;
    }
};