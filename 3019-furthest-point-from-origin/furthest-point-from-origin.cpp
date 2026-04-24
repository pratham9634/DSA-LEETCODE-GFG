class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        int lc=0,rc=0;

        for(int i=0;i<n;i++){
            if(moves[i]=='L')lc++;
            else if (moves[i]=='R')rc++;
        }
        int dc = n - lc-rc;
        return abs(lc-rc) +dc;
    }
};