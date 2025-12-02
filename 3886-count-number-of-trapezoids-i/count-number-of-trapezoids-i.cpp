class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,int>mp;
        const int mod = 1e9 + 7;
        long long ans = 0,sum = 0;
        for(auto& p : points){
            mp[p[1]]++;
        }
        for(auto&[_,pnum]:mp){
            long long edge = (long long)pnum*(pnum-1)/2;
            ans+=edge*sum;
            sum+=edge;
        }
        return ans%mod;
    }
};