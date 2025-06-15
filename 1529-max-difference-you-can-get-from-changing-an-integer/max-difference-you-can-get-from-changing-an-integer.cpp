class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string t = s;
        size_t pos = s.find_first_not_of('9');
         if (pos != string::npos) {
            char a = s[pos];
            replace(s.begin(), s.end(), a, '9');
        }
        
        char b = 'z';
        if(t[0]=='1'){
            for(int i=1;i<s.length();i++){
                if(t[i]!='0'&&t[i]!='1'){
                    b = t[i];
                    break;
                }
            }
            replace(t.begin(), t.end(), b, '0');
    
        }
        else {
             b=t[0];
            replace(t.begin(), t.end(), b, '1');
        }
        return stoi(s) - stoi(t);
        return 0;
    }
};