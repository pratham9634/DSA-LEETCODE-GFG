class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.length();
        int m = b.length();
        string ans ;
        int carry = 0;

        int i = n-1, j = m-1;

        while(i>=0 || j>=0 ||carry){
            if(i>=0) carry += a[i--] - '0';
            if(j>=0) carry += b[j--] - '0';

            ans += carry%2 + '0';
            carry /= 2;
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};