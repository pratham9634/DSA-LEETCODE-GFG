class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int zeroCnt=0;
        int maxlen=0;
        int left=0;
        for(int right=0;right<n;right++){
            if(nums[right]==0) zeroCnt++;
            while(zeroCnt>1){
                if(nums[left]==0) zeroCnt--;
                left++;
            }
        maxlen=max(maxlen,right-left);
        }
        return maxlen;
    }
};