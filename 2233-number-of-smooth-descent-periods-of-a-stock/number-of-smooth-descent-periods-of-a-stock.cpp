class Solution {
public:
    long long getDescentPeriods(vector<int>& p) {
        long long ans = 1;
        long long count = 1;
        int n = p.size();
        for(int i=1;i<n;i++){
            if(p[i-1]-p[i]==1) count++;
            else count = 1;
            ans+=count;
        }
        return ans;
    }
};