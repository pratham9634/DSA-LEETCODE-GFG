class Solution {
public:
    bool detectCapitalUse(string s) {
        int n = s.length();
        int c = 0;
        for(int i=0;i<n;i++){
            if(s[i]>=65 && s[i]<=90) c++;
        }
        if(s[0]>=65 && s[0]<=90 && c==1) return true;
        if(c==n) return true;
        if(c==0) return true;
        return false;
    }
};