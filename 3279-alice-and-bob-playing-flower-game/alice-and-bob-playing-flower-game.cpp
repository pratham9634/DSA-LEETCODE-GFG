class Solution {
public:
    long long flowerGame(int n, int m) {
        long long ne = 0,no = 0,me =0,mo=0;
        ne = n/2;
        no = n-ne;
        me = m/2;
        mo = m-me;
        return (ne*mo+me*no);
    }
};