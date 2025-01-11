class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();
        if(n<k) return false;
        int c = 0;
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        for(auto &it : mp){
            if(it.second%2==1)c++;
        }
        if(c>k) return false;
        return true;
    }
};