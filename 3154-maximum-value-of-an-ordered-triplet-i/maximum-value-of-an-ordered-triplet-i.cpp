class Solution {
public:
    
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        
        vector<int> left_max(n);
        left_max[0]=nums[0];
        for(int i=1;i<n;i++) left_max[i]=max(left_max[i-1],nums[i]);
        
        vector<int> right_max(n);
        right_max[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--) right_max[i]=max(right_max[i+1],nums[i]);
        
        long ans=0;
        
        for(int i=1;i<n-1;i++){
            long val = (long)(left_max[i-1]-nums[i])*(long)right_max[i+1];
            if(ans < val) ans=val;
        }
        
        return ans;
    }
};