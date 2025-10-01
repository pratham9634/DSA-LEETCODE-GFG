class Solution {
public:
    int maxBottlesDrunk(int nb, int ne) {
        int ans = nb;
        int e = nb;
        int fb = 0;
        while(e>=ne){
            e-=ne;
            fb++;
            ne++;
            if(e<ne){
                e+=fb;
                ans+=fb;
                fb = 0;
            }
        }
        return ans+fb;
    }
};