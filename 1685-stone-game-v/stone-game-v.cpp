class Solution {
public:
    int t[501][501];
    int solve(int l, int r, vector<int>& psum) {

        if(l>=r) return 0;
         if(t[l][r] != -1) {
            return t[l][r];
        }
        int ans = 0;

        for(int m=l;m<r;m++){
            int ls = psum[m] - (l-1>=0?psum[l-1]:0);
            int rs = psum[r] - psum[m];

            if(ls<rs){
                ans = max(ans,ls+solve(l,m,psum));
            }else if(ls>rs){
                ans = max(ans,rs+solve(m+1,r,psum));
            }else{
                ans = max({ans,(ls+solve(l,m,psum)),(rs+solve(m+1,r,psum))});
            }
        }
        return t[l][r]=ans;
    }
    int stoneGameV(vector<int>& s) {
        int n = s.size();
        vector<int>psum(n,0);
        psum[0] = s[0];
        for(int i=1;i<n;i++){
            psum[i] += (psum[i-1]+s[i]);
        }
        memset(t,-1,sizeof(t));
        return solve(0,n-1,psum);
    }
};