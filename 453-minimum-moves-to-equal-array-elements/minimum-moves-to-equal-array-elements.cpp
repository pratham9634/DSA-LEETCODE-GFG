class Solution {
public:
    int minMoves(vector<int>& nums) {
        int me = INT_MAX;
        int ans = 0;
        for(int x : nums){
            me = min(me,x);
            ans+=x;
        }
        return ans-(me*nums.size());
    }
};