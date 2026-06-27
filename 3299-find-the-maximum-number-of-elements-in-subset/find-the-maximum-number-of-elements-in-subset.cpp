class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long,int>mp;
        int n = nums.size();

        for(int num : nums){
            mp[num]++;
        }
        int ans = 0;
        int oc = mp[1];
        if(oc%2==1){
            ans = oc;
        }else ans = oc-1;

        mp.erase(1);

        for(auto& [num,_] : mp){
            int res = 0;
            long long x = num;
            for(;mp.contains(x)&&mp[x]>1;x *=x){
                res += 2;
            }
            ans = max(ans,res+(mp.contains(x)?1:-1));
        }
        return ans;
    }
};