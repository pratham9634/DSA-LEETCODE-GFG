class Solution {
public:
    unordered_map<char,char> p;
    char find(char x) {
        if (p[x] != x)
            p[x] = find(p[x]); 
        return p[x];
    }
    void comb(char x, char y) {
    char px = find(x);
    char py = find(y);
    if (px == py) return;
    char z = min(px, py);
    p[px] = z;
    p[py] = z;
}

    string smallestEquivalentString(string s1, string s2, string b) {
        string ans = "";
        
        for(int i=0;i<26;i++){
            char ch = 'a' + i;
            p[ch] = ch;
        }

        int n = s1.length();
        for(int i=0;i<n;i++){
            comb(s1[i],s2[i]);
        }
        for(int i=0;i<b.length();i++){
            ans.push_back(find(b[i]));
        }
        return ans;
    }
};