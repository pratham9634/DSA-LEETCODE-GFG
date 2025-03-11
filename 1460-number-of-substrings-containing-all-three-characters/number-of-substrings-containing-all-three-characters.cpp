class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> mp;
        int n = s.length();
        int j =0,ans = 0;
        for(int i=0;i<n;i++){
            while(j<n && mp.size()<3){
                mp[s[j]]++;
                j++;
            }
            if( mp.size()==3) ans +=(n-j+1);
            mp[s[i]]--;
            if(mp[s[i]]==0) mp.erase(s[i]);
        }
        return ans;
    }
};
