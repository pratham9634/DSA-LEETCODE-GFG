class Solution {
public:
    typedef long long ll;
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll sum = 0;
        int count = 0 ; 
        ll minloss = INT_MAX;
        for(ll num : nums){
            if( (long long)(num^k)>num){
                count++;
                sum+=(long long)(num^k);
            }
            else {
                sum+=num;
            }
            minloss = min(minloss,abs(num-(long long)(num^k)));
        }
        if(count%2==1) return sum-minloss;
        return sum;
    }
};