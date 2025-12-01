class Solution {
public:
    int n;
    bool ip(string &s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(string &s,int idx, vector<string> curr,vector<vector<string>>&ans){
        if(idx==n){
            ans.push_back(curr);
            return;
        }

        for(int i=idx;i<n;i++){
            if(ip(s,idx,i)){
                curr.push_back(s.substr(idx,i-idx+1));
                solve(s,i+1,curr,ans);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n = s.length();
        vector<vector<string>>ans;
        vector<string> curr;

        solve(s,0,curr,ans);

        return ans;
    }
};