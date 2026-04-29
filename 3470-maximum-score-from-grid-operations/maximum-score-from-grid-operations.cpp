class Solution {
public:
    typedef long long ll;
    int n;
    ll t[2][101][101];

    ll solve(bool pt,int ph,int c,vector<vector<ll>>& psum){
        if(c==n) return 0;

        ll ans = 0;

        if(t[pt][ph][c]!= -1){
            return t[pt][ph][c];
        }

        for(int h=0;h<=n;h++){
            ll pcs = 0;
            ll ccs = 0;

            if(!pt && c-1>=0&&ph<h){
                pcs += psum[h][c] - psum[ph][c];
            }
            if(ph>h){
                ccs += psum[ph][c+1] - psum[h][c+1];
            }

            ll taken = ccs+pcs+solve(true,h,c+1,psum);
            ll ntake = pcs+solve(false,h,c+1,psum);

            ans =  max({ans,taken,ntake});

        }

        return t[pt][ph][c] = ans;
    }

    long long maximumScore(vector<vector<int>>& grid) {
        n = grid.size();

        memset(t, -1, sizeof(t));

        vector<vector<ll>>psum(n+1,vector<ll>(n+1,0));
        for(int j=1;j<=n;j++){
            for(int i=1;i<=n;i++){
                psum[i][j] = psum[i-1][j] + grid[i-1][j-1];
            }
        }
        return solve(false,0,0,psum);
    }
};