class Solution {
public:
    int mod = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> l(n,-1);
        vector<int> r(n,n);
        stack<int> st;

        for(int i=0;i<n;i++){
            while(!st.empty()&& arr[st.top()]>=arr[i])st.pop();
            if(!st.empty()) l[i] = st.top();
            st.push(i);
        }

        st = stack<int>();

        for(int i=n-1;i>=0;i--){
            while(!st.empty()&& arr[st.top()]>arr[i])st.pop();
            if(!st.empty()) r[i] = st.top();
            st.push(i);
        }

        long long sum =0;
        for(int i=0;i<n;i++){
            sum += static_cast<long long>(i-l[i])*(r[i]-i)*arr[i] % mod;
            sum %= mod;
        }
        return sum;
    }
};