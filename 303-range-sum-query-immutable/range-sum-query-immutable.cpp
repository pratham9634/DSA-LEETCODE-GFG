class NumArray {
public:
    int n;
    vector<int>psum;
    NumArray(vector<int>& nums) {
        n = nums.size();
        psum.resize(n,0);
        for(int i=0;i<n;i++){
            if(i==0){
                psum[i] = nums[i];
            }
            else psum[i] += psum[i-1]+nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        if(left==0) return psum[right];
        return psum[right] - psum[left-1];
    }
};

