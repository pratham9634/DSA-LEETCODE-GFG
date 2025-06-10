class Solution {
public:
    int maxDifference(string s) {
        int x=INT_MAX,y=INT_MIN;
        unordered_map<char,int>mp;
        for(char c:s){
            mp[c]++;
        }
        for(auto& p :mp){
            if(p.second%2==0) x = min(x,p.second);
            else y = max(y,p.second);
        }
        return y-x;
    }
};