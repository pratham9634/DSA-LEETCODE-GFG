class Solution {
public:
    vector<string> ans;
    unordered_map<char, vector<string>> mp = {
        {'2', {"a", "b", "c"}},
        {'3', {"d", "e", "f"}},
        {'4', {"g", "h", "i"}},
        {'5', {"j", "k", "l"}},
        {'6', {"m", "n", "o"}},
        {'7', {"p", "q", "r", "s"}},
        {'8', {"t", "u", "v"}},
        {'9', {"w", "x", "y", "z"}}
    };
    void solve(int i,string &str,string prev){
        if(i==str.length()){
            if(prev!="")ans.push_back(prev);
            return;
        }
        for(auto it : mp[str[i]]){
            solve(i+1,str,prev+it);
        }
    }
    vector<string> letterCombinations(string digits) {
        solve(0,digits,"");
        if(ans.size()) return ans;
        return {};
    }
};