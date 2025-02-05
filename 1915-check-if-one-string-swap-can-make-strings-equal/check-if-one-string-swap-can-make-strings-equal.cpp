class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) return true; 
        
        vector<int> v;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                v.push_back(i);
            }
        }

        if (v.size() != 2) return false; 
        
        int i1 = v[0], i2 = v[1];
        return (s1[i1] == s2[i2] && s1[i2] == s2[i1]); 
    }
};
