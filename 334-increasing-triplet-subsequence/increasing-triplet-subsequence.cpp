class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec(n);
        int x = nums[n-1];
        for(int i=n-1;i>=0;i--){
            x = max(nums[i],x);
            vec[i] = x;
        }

        x = nums[0];
        for(int i=1;i<n-1;i++){
            if(x<nums[i]&&nums[i]<vec[i]) return true;
            x= min(x,nums[i]);
        }
        return false;
    }
};