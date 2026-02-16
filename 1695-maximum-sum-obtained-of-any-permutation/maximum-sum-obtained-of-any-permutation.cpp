class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& r) {
        int n = nums.size();
        int M = 1e9 + 7;
        vector<int>e(n,0);
        for(int i=0;i<r.size();i++){
            e[r[i][0]]++;
            if(r[i][1]+1<n) e[r[i][1]+1]--;
        }

        for(int i=1;i<n;i++){
            e[i]+=e[i-1];
        }
        int ans = 0;

        sort(e.begin(),e.end(),greater<int>());
        sort(nums.begin(),nums.end(),greater<int>());

        for(int i=0;i<n;i++){
            ans = (ans + (1LL *nums[i]*e[i])%M)%M;
        }
        return ans;
    }
};