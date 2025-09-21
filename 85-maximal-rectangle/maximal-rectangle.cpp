class Solution {
public:
    vector<int> NSR(vector<int>&h){
         stack<int> st;
        int n = h.size();
        int idx = n;
        vector<int> r(n);

        for(int i=n-1;i>=0;i--){
            if(st.empty()) r[i]=idx;
            else{
                 while(!st.empty() && h[st.top()] >= h[i])
                    st.pop();
                if(st.empty())
                    r[i] = idx;
                else
                    r[i] = st.top();
            }
            st.push(i);
        }
        return r;
    }
    vector<int> NSL(vector<int>&h){
        stack<int> st;
        int n = h.size();
        int idx = -1;
        vector<int> l(n);

        for(int i=0;i<n;i++){
            if(st.empty()) l[i]=idx;
            else{
                 while(!st.empty() && h[st.top()] >= h[i])
                    st.pop();
                if(st.empty())
                    l[i] = idx;
                else
                    l[i] = st.top();
            }
            st.push(i);
        }
        return l;
    }
    int helper(vector<int> &h){
        int n = h.size();
        vector<int> r = NSR(h);
        vector<int> l = NSL(h);
        int area = 0;

        for(int i=0;i<n;i++){
            int a = (r[i]-l[i]-1)*h[i];
            area = max(a,area);
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& mat) {
        if(mat.size()==0) return 0;
        int n = mat.size();
        int m = mat[0].size();
        vector<int>h(m);
        for(int i=0;i<m;i++){
            h[i] = (mat[0][i]=='1')?1:0;
        }
        int ans = helper(h);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='0')h[j]=0;
                else h[j] += 1;
            }
            ans = max(ans,helper(h));
        }
        return ans;
    }
};