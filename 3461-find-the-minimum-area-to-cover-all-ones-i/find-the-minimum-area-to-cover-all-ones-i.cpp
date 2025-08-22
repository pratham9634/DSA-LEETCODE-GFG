class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
         int n = grid.size();
         int m = grid[0].size();

         int minr = n;
         int maxr = -1;
         int minc = m;
         int maxc = -1;
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    minr = min(minr,i);
                    minc = min(minc,j);
                    maxr = max(maxr,i);
                    maxc = max(maxc,j);
                }
            }
         }
         return (maxr-minr+1)*(maxc-minc+1);
    }
};