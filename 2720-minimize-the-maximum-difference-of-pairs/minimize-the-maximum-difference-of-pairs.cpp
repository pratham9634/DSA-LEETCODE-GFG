class Solution {
public:
    bool helper(vector<int>& nums,int p,int m){
        int count = 0;
        int i=0;
        while(i<nums.size()-1){
            if(nums[i+1]-nums[i]<=m){
                count++;
                i+=2;
            }
            else i++;
        }
        return count>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int l = 0;
        int r = nums[n-1]-nums[0];
        int ans = INT_MAX; 
        while(l<=r){
            int m = (l+r)/2;
            if(helper(nums,p,m)){
                ans = m;
                r=m-1;
            }
            else l=m+1;
        }
        return ans;
    }
};