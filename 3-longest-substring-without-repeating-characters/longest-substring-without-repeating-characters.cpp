class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 1;
        int n = s.length();
        if(n==0) return 0;
        unordered_map<char,int > mp;
        int j = 0;
        for(int i=0;i<n;i++){
            while(mp.count(s[i])){
                mp[s[j]]--;
                if(mp[s[j]]==0) mp.erase(s[j]);
                j++;
            }
            mp[s[i]]++;
            ans = max(ans,i-j+1);
        }
        return ans;
    }
};