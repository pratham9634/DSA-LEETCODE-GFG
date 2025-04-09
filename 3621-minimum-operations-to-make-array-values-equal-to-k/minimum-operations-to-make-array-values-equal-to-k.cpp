class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int count = 0;
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]) count++;
        }
        if(nums[0]<k) return -1;
        if(nums[0]==k) return count;
        return count+1;
    }
};