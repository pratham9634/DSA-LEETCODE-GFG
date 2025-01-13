class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        unordered_map<char,int> mp;
        int ans = n;

        for(int i =0;i<n;i++){
            mp[s[i]]++;
        }

        for(auto &c : mp){
            if(c.second>=3 && c.second%2==1) ans -=(c.second-1) ;
            if(c.second>=3 && c.second%2==0) ans -=(c.second-2) ;
        }
        return ans;
    }
};