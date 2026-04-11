class Solution {
public:
    int mod = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int>ps(n,-1);
        vector<int>ns(n,n);

        stack<int>st;

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]<=arr[st.top()]) st.pop();
            if(!st.empty()) ps[i] = st.top();
            st.push(i);
        }
        st = stack<int>();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[i]<arr[st.top()]) st.pop();
            if(!st.empty()) ns[i] = st.top();
            st.push(i);
        }
        long long ans = 0;
        for(int i=0;i<n;i++){
            ans += static_cast<long long>(i-ps[i])*(ns[i]-i)*arr[i];
            ans %= mod;
        }
        return ans;

    }
};