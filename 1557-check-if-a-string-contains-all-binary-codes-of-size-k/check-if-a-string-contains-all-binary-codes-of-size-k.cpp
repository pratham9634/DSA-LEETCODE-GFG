class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_map<string,int> mp;
        int i=0;

        while(i+k<=s.length()){
            mp[s.substr(i,k)]++;
            i++;
        }

        return mp.size()==(1<<k);

    }
};