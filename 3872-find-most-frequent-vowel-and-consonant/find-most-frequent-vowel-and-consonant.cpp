class Solution {
public:
    int maxFreqSum(string s) {
        int n = s.length();
        int  x = 0,y=0;
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        for(auto it:mp){
            if(it.first=='a'||it.first=='e'||it.first=='i'||it.first=='o'||it.first=='u'){
                x = max(x,it.second);
            }
            else  y = max(y,it.second);
        }
        return x+y;
    }
};