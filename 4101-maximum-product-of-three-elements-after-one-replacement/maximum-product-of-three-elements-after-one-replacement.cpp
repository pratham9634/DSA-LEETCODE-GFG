class Solution {
public:
    pair<long long, long long> twoMax(vector<int> a) {
    long long x = 0, y = 0;

    for(long long v : a) {
        if(llabs(v) > llabs(x)) {
            y = x;
            x = v;
        }
        else if(llabs(v) > llabs(y)) {
            y = v;
        }
    }

    return {x, y};
}
    long long maxProduct(vector<int>& nums) {
        int n = nums.size();

        auto curr = twoMax(nums);
        long long ans = curr.first * curr.second;

        return ans>=0?ans*100000:ans*(-100000);
    }
};