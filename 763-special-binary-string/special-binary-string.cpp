class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> st;

        int sum = 0,start = 0;

        for(int i=0;i<s.length();i++){
            sum += s[i] == '1' ? 1 : -1;

            if(sum == 0){
                string inner = s.substr(start+1 ,i-start-1);
                st.push_back("1" + makeLargestSpecial(inner) + "0");
                start = i+1;
            }
        }
        sort(st.begin(),st.end(),greater<string>());
        string res ;
        for(string &s : st){
            res += s;
        }
        return res;
    }
};