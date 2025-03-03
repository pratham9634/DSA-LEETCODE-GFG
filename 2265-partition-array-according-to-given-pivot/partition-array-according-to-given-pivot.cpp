class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans1;
        vector<int> ans2;
        int count=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot) ans1.push_back(nums[i]);
            else if(nums[i]>pivot)  ans2.push_back(nums[i]);
            else count++;
        }

        while(ans1.size()<nums.size()){
            for(int i=0;i<count;i++) ans1.push_back(pivot);
             for(int j=0;j<ans2.size();j++) ans1.push_back(ans2[j]);
        }
        return ans1;
    }
};