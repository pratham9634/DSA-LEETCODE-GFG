class Solution {
public:
    string minWindow(string s, string t) {
        int  n = s.size();
        int m = t.size();
        if(m>n) return "";
        unordered_map<char,int>mp;
        for(int i=0;i<m;i++){
            mp[t[i]]++;
        }
        unordered_map<char,int>mp2;
        int req = mp.size();
        int form = 0;
        int l=0,r=0;
        int ans = INT_MAX,st=0;
        while(r<n){
            char c = s[r];
            mp2[c]++;

            if(mp.count(c) && mp[c]==mp2[c]){
                form++;
            }

            while(l<=r && form==req){
                if(r-l+1<ans){
                    ans = r-l+1;
                    st = l;
                }
                char d = s[l];
                mp2[d]--;
                if(mp.count(d) && mp2[d]<mp[d]) form--;
                l++;
            }
            r++;
        }
        return ans==INT_MAX?"":s.substr(st,ans);
    }
};