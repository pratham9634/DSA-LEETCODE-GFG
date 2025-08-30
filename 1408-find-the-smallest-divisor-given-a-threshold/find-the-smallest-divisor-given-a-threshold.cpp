class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int r = *max_element(nums.begin(),nums.end());

        while(l<r){
            int m = l + (r-l)/2;
            int d = 0;
            for(int n : nums){
                d+=(n-1)/m+1;
            }
            if(d<=threshold)r=m;
            else l =m+1;
        }
        return l;
    }
};