class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        stack<int> st;
        vector<int> nsi(n,n);
        vector<int> psi(n,-1);

        for(int i=0;i<n;i++){
            while(!st.empty() && h[st.top()]>h[i]) st.pop();
            if(!st.empty()) psi[i]=st.top();
            st.push(i);
        }
        st = stack<int>();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && h[st.top()]>=h[i]) st.pop();
            if(!st.empty()) nsi[i]=st.top();
            st.push(i);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            int curr = ((i-psi[i])+(nsi[i]-i)-1)*h[i];
            ans = max(ans,curr);
        }
        return ans;
    }
};