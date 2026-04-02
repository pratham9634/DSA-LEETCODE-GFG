class Solution {
public:
    int m;
    int n;
    int t[501][501][3];
    int solve(vector<vector<int>>&arr,int i,int j,int k){
        if(i==n-1 && j==m-1){
            if(arr[i][j]<0 && k>0) return 0;
            return arr[i][j];
        }
        if(i>=n || j>=m ) return INT_MIN;
        if(t[i][j][k]!=INT_MIN) return t[i][j][k];

        int take = arr[i][j] + max(solve(arr,i+1,j,k),solve(arr,i,j+1,k));
        int skip = INT_MIN;

        if(arr[i][j]<0 && k>0){
            skip = max(solve(arr,i+1,j,k-1),solve(arr,i,j+1,k-1));
        }
        return t[i][j][k] = max(take,skip);
    }
    int maximumAmount(vector<vector<int>>& coins) {
        n = coins.size();
        m = coins[0].size();
        for(int i=0;i<501;i++){
            for (int j=0;j<501;j++){
                for(int k=0;k<3;k++){
                    t[i][j][k] = INT_MIN;
                }
            }
        }
        return solve(coins,0,0,2);
    }
};