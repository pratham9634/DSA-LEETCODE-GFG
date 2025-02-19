class Solution {
public:
    void helper(string s,int &n,int &k,vector<string> &ans){
        if(ans.size()==k) return;
        if(s.size()==n){ 
            ans.push_back(s);
            return;
        }
        if (s.back() == 'a') {
            helper(s + "b", n, k, ans);
            helper(s + "c", n, k, ans);
        } 
        else if (s.back() == 'b') {
            helper(s + "a", n, k, ans);
            helper(s + "c", n, k, ans);
        } 
        else if (s.back() == 'c') {
            helper(s + "a", n, k, ans);
            helper(s + "b", n, k, ans);
        }
    }
    string getHappyString(int n, int k) {
        vector<string> ans;
        helper("a",n,k,ans);
        helper("b",n,k,ans);
        helper("c",n,k,ans);
        if(ans.size()<k) return "";
        return ans[k-1];
    }
};