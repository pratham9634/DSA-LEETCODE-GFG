class Solution {
public:
    void solve(vector<int>&curr,int num,vector<vector<int>>&ans,int n,int k){
        if(k==0){
            ans.push_back(curr);
            return;
        }
        for(int i=num;i<=n;i++){
            curr.push_back(i);
            solve(curr,i+1,ans,n,k-1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        vector<vector<int>>ans;
        solve(curr,1,ans,n,k);
        return ans;
    }
};