class Solution {
public:
    bool checkValid(vector<vector<int>>& m) {
        int n = m.size();

        for(int i=0;i<n;i++){
            unordered_map<int,int>mp;
            for(int j=0;j<n;j++){
                mp[m[i][j]]++;
            }
            if(mp.size()!=n) return false; 
        }
        for(int i=0;i<n;i++){
            unordered_map<int,int>mp;
            for(int j=0;j<n;j++){
                mp[m[j][i]]++;
            }
            if(mp.size()!=n) return false; 
        }
        return true;
    }
};