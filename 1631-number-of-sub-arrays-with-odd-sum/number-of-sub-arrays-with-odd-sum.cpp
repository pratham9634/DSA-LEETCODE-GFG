class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long oc = 0, ec=0,ps= 0;
        int ans = 0;
        for(int a : arr) {
            ps += a;
            if(ps % 2){
                oc++;
                ans++;
                ans += ec;
                ans %= 1'000'000'007;
            }
            else{
                ec++;
                ans += oc;
                ans %= 1'000'000'007;
                
            }
        }
        return ans % 1'000'000'007;
    }
};