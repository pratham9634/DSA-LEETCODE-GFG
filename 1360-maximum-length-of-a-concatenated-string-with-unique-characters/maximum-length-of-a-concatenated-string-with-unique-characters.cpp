class Solution {
public:
    void solve(int idx , int temp ,int &ans,vector<int> &uc){
        ans = max(ans,__builtin_popcount(temp));

        for(int i=idx ;i<uc.size();i++){
            if((temp & uc[i])==0) solve(i+1,temp | uc[i],ans,uc);
        }
    }
    int maxLength(vector<string>& arr) {
        vector<int> uc;

        for(string &s : arr){
            unordered_set<char> st(begin(s),end(s));
            if(st.size()!=s.size()) continue;

            int val = 0 ;
            for( char &ch : s){
                val |= 1 << (ch - 'a');
            }
            uc.push_back(val);
        }
        int ans = 0;
        solve(0,0,ans,uc);
        return ans;
    }
};