class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int ans = INT_MAX;

        for(int r=0;r<n;r++){
            int ops = r;

            for(int i=0;i<n/2;i++){
                char l = s[(i+r)%n];
                char rs = s[(n-i-1+r)%n];

                int c1 = (rs - l + 26)%26;
                int c2 = (l - rs + 26)%26;

                ops += min(c1,c2);

            }
            ans = min(ans,ops);
        }
        return ans;
    }
};