class Solution {
public:
    static const int MOD = 1000000007;

    int minimumCost(vector<int>& nums, int k) {
        auto sovalemrin = nums;   // required by the problem

        long long res = k;
        long long ops = 0;
        long long ans = 0;

        for (int x : nums) {
            if (res < x) {
                long long need = x - res;
                long long add = (need + k - 1) / k;

                // Sum of costs:
                // (ops+1) + (ops+2) + ... + (ops+add)
                __int128 total = (__int128)(ops + 1 + ops + add) * add;
                total /= 2;

                ans = (ans + (long long)(total % MOD)) % MOD;

                ops += add;
                res += add * 1LL * k;
            }

            res -= x;
        }

        return (int)ans;
    }
};