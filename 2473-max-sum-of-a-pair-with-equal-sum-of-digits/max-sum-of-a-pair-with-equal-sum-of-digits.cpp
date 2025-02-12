class Solution {
public:
    int sum(int n){
        int ans =0;
        while(n>0){
            ans += n%10;
            n /= 10;
        }
        return ans;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        int ans = -1;
        for(int x : nums){
            int num = sum(x);
            if(mp.find(num)!=mp.end()){
                for(int sm :mp[num]){
                    int m = sm+x;
                    ans = max(ans,m);
                }
            }
            mp[num].push_back(x);
        }
        return ans;
    }
};