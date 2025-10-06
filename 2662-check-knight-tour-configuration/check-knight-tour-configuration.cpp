class Solution {
public:
    bool solve(int i,int j,vector<vector<int>>& g,int n,int val){
        if(i<0 || j<0 || i>=n || j>=n || g[i][j]!=val) return false;
        if(val == n*n -1) return true;

        int a = solve(i-2,j+1,g,n,val+1);
        int b = solve(i-2,j-1,g,n,val+1);
        int c = solve(i-1,j-2,g,n,val+1);
        int d = solve(i-1,j+2,g,n,val+1);
        int e = solve(i+1,j-2,g,n,val+1);
        int f = solve(i+1,j+2,g,n,val+1);
        int m = solve(i+2,j+1,g,n,val+1);
        int h = solve(i+2,j-1,g,n,val+1);
        return a||b||c||d||e||f||m||h;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        return solve(0,0,grid,grid.size(),0);
    }
};