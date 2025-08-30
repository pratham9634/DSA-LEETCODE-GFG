class Solution {
public:
    int shipWithinDays(vector<int>& w, int d) {
        int n = w.size();
        int tw = 0, mx = 0;
        for(int x : w){
            tw += x;
            mx = max(mx, x);
        }
        
        int l = mx, r = tw;
        while(l < r){
            int m = l + (r - l) / 2;
            
            int td = 1; // start with 1 day
            int wei = 0;
            for(int i = 0; i < n; i++){
                if(wei + w[i] > m){ // need new day
                    td++;
                    wei = 0;
                }
                wei += w[i];
            }
            
            if(td > d) l = m + 1; // capacity too small
            else r = m;           // capacity works, try smaller
        }
        return l;
    }
};
