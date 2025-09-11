class Solution {
public:
    bool isVowel(char c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U') return true;
        return false;
    }
    string sortVowels(string s) {
        int n = s.length();
        string t = s;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            if(isVowel(s[i])){
                mp[(int)(s[i]-'A')]++;
            }
        }
        int i = 0;
        for(auto it : mp){
            char x = (char)(it.first)+'A';
            int c = it.second;

            while(c>0){
                if(isVowel(t[i])){
                    t[i]=x;
                    c--;
                }
                i++;
            }
        }
        return t;
    }
};