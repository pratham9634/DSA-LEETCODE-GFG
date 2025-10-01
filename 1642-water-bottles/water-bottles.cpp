class Solution {
public:
    int numWaterBottles(int fb, int ex) {
        int ans = 0;
        int e = 0;
        while(fb){
            ans+=fb;
            e+=fb;
            fb = e/ex;
            e = e%ex;
        }
        return ans;
    }
};