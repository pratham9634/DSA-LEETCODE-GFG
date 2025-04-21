class Solution {
public:
    int numberOfArrays(vector<int>& d, int l, int u) {
        long long x = 0, mp = 0, mxp = 0;
        
        for (int i = 0; i < d.size(); ++i) {
            x += d[i];
            mp  = min(mp, x);
            mxp  = max(mxp , x);
        }

        long long low = l - mp;
        long long high = u - mxp ;

        if (low > high) return 0;
        return high - low + 1;
    }
};
