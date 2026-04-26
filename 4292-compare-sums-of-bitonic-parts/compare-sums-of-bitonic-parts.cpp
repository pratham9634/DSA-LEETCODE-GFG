class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n = nums.size();


        long long total = 0;
        for(int x : nums) total += x;


        int peak = 0;
        for(int i = 1; i < n - 1; i++) {
            if(nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                peak = i;
                break;
            }
        }


        long long lsum = 0;
        for(int i = 0; i < peak; i++) {
            lsum += nums[i];
        }

 
        long long rsum = total - lsum - nums[peak];

        if(lsum > rsum) return 0;
        else if(rsum > lsum) return 1;
        return -1;
    }
};