class Solution {
public:
    typedef long long ll;
    ll solve(vector<int>&r,vector<int>&pos,int ri,int fi,vector<vector<ll>>&t){
        if(ri>=r.size()) return 0;
        if(fi>=pos.size()) return 1e12;

        if(t[ri][fi]!= -1) return t[ri][fi];

        ll take = abs(r[ri]-pos[fi])+solve(r,pos,ri+1,fi+1,t);
        ll skip = solve(r,pos,ri,fi+1,t);
        return t[ri][fi] = min(take,skip);
    }
    long long minimumTotalDistance(vector<int>& r, vector<vector<int>>& f) {
        sort(begin(r),end(r));
        sort(begin(f),end(f));
        vector<int>pos;
        int m = r.size();
        for(int i=0;i<f.size();i++){
            int limit = f[i][1];
            for(int j=0;j<limit;j++) pos.push_back(f[i][0]);
        }
        int n = pos.size();
        vector<vector<ll>>t(m+1,vector<ll>(n+1,-1));

        return solve(r,pos,0,0,t);
    }
};