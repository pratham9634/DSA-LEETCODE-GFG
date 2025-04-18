class Solution {
public:
    

    string countAndSay(int n) {
        if (n == 1) return "1";
        string s = "1";
        
        for (int i = 1; i < n; i++) { 
            string a = "";
            int c = 1;
            
            for (int j = 1; j < s.length(); j++) {
                if (s[j] == s[j - 1]) {
                    c++;
                } else {
                    a += to_string(c);
                    a.push_back(s[j - 1]);
                    c = 1;
                }
            }
            a += to_string(c);         
            a.push_back(s.back());    
            s = a;
        }
        
        return s;
    }
};