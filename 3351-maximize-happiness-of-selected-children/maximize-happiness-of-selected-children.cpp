class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        long long ans = 0;
        int n = h.size();
        sort(h.begin(),h.end());
        int red = 0;
        for(int i=0;i<k;i++){
            ans += max(0,h[n-1-i]-red);
            red++;
        }
        return ans;
    }
};