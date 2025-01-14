class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n,0);
        unordered_map<int,int> mp;
        int cans = 0;

        for(int i=0;i<n;i++){
            mp[A[i]]++;
            mp[B[i]]++;
            if(A[i]!=B[i]){
                if(mp[A[i]]==2) cans++;
                if(mp[B[i]]==2) cans++;
            }
            else{
                if(mp[A[i]]==2) cans++;
            }
            ans[i] = cans;
        }

        return ans;
    }
};