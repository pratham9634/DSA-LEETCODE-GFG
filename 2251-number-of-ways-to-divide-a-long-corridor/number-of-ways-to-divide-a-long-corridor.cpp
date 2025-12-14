class Solution {
public:
    int mod = 1e9 + 7;
    int numberOfWays(string c) {
        vector<int> st;
        for(int i=0;i<c.size();i++){
            if(c[i]=='S') st.push_back(i);
        }
        if(st.size()%2 || st.size()==0 ) return 0;

        long long ans = 1;
        int prev = st[1];

        for(int i=2;i<st.size();i+=2){
            int len  = st[i]-prev;
            ans = (ans*len)%mod;
            prev = st[i+1];
        }
        return ans;
    }
};