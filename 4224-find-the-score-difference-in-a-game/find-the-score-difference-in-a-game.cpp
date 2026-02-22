class Solution {
public:
    
    int scoreDifference(vector<int>& nums) {
        int active = 0;
        int s = 0;
        bool flag = true;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2) flag=!flag;
            if(i%6==5) flag=!flag;
            if(flag) active+=nums[i];
            else s+=nums[i];
        }
        return active-s;
    }
};