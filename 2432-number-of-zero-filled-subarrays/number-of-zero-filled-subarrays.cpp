class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long count=0;
        long long set=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                set++;
                count+=set;
            }else set=0;
            
        }
        return count;
    }
};