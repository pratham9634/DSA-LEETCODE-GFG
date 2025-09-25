class Solution {
public:
    void helper(int n , string prev,int count,vector<string>&ans){
        if(prev.length()==2*n){
            if(count==0) ans.push_back(prev);
            return;
        }
        if(count>0){
            helper(n,prev+"(",count+1,ans);
            helper(n,prev+")",count-1,ans);
        }
        else helper(n,prev+"(",count+1,ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(n,"(",1,ans);
        return ans;
    }
};