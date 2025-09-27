class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int flip = 0;
        deque<int> dq;
        int pf = 0;

        for(int i=0;i<n;i++){
            if(i>=k){
                pf -= dq.front();
                dq.pop_front();
            }
            if(pf%2==nums[i]){
                if(i+k>n) return -1;
                pf++;
                dq.push_back(1);
                flip++;
            }else{
                dq.push_back(0);
            }
        }
        return flip;
    }
};