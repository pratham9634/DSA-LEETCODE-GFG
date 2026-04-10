class Solution {
public:
    int n;
    bool helper(string s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(int idx,string s,vector<string>&curr,vector<vector<string>>&ans){

        if(idx==n){
            ans.push_back(curr);
            return;
        }
        for(int i=idx;i<n;i++){
            if(helper(s,idx,i)){
                curr.push_back(s.substr(idx,i-idx+1));
                solve(i+1,s,curr,ans);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n = s.length();
        vector<vector<string>>ans;
        vector<string>curr;
        solve(0,s,curr,ans);
        return ans;
    }
};