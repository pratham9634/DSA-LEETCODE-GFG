class Solution {
public:
    int t[51][51];
    int solve(vector<int>&v,int i,int j){

        if(j-i+1<3) return 0;
        if(t[i][j]!=-1) return t[i][j];
        int ans = INT_MAX;

        for(int k=i+1;k<j;k++){
            int res = (v[i]*v[j]*v[k]) + solve(v,i,k) + solve(v,k,j);
            ans = min(ans,res);
        }
        return t[i][j] =ans;
    }
    int minScoreTriangulation(vector<int>& v) {
        int n = v.size();
        memset(t,-1,sizeof(t));
        return solve(v,0,n-1);
    }
};