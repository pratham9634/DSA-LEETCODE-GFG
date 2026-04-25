class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& p, string s) {
        unordered_map<char,int>mp;
        int sm = INT_MAX,ans=0;

        for(int i=0;i<p.size();i++){
            int len = max(abs(p[i][0]),abs(p[i][1]));
            char c = s[i];

            if(mp.find(c)==mp.end()){
                mp[c] = len;
            }else if(len<mp[c]){
                sm = min(sm,mp[c]);
                mp[c] = len;
            }else{
                sm = min(sm,len);
            }
        }
        for(auto &it:mp){
            if(it.second<sm) ans++;
        }
        return ans;
    }
};