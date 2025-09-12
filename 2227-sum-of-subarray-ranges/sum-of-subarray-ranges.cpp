class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int>ngi(n,n);
        vector<int>nsi(n,n);
        vector<int>pgi(n,-1);
        vector<int>psi(n,-1);

        stack<int> st;

        for(int i=0;i<n;i++){
            while(!st.empty() && nums[i]>nums[st.top()]) st.pop();
            if(!st.empty()) pgi[i] = st.top();
            st.push(i);
        }
        st = stack<int>();
         for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[i]>=nums[st.top()]) st.pop();
            if(!st.empty()) ngi[i] = st.top();
            st.push(i);
        }
        st = stack<int>();
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[i]<nums[st.top()]) st.pop();
            if(!st.empty()) psi[i] = st.top();
            st.push(i);
        }
        st = stack<int>();
         for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[i]<=nums[st.top()]) st.pop();
            if(!st.empty()) nsi[i] = st.top();
            st.push(i);
        }
        long long ans =0;

        for(int i=0;i<n;i++){
            long long mns = (long long)(i-psi[i])*(nsi[i]-i)*nums[i];
            long long mxs = (long long)(i-pgi[i])*(ngi[i]-i)*nums[i];
            ans += (mxs-mns);
        }
        return ans;
    }
};