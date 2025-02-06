class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int,int> mp;

        for(int i=0;i<n-1;i++){
            for(int j = i+1;j<n;j++){
                int x = nums[i]*nums[j];
                mp[x]++;
            }
        }
        for(auto p :mp){
            if(p.second>1)
            ans += 4*(p.second*(p.second-1));
        }

        return ans ;
    }
};