class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        int n = nums.size();
        int r = 0,ans = n;

        for(int l=0;l<n;l++){
            while(r<n && nums[r]<=static_cast<long long>(nums[l])*k) r++;
            ans = min(ans,n-(r-l));
        }
        return ans;
    }
};