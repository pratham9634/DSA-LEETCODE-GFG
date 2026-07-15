class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int so = n*n;
        int se = n*n + n;
        return __gcd(se,so);
    }
};