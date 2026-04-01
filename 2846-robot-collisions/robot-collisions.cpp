class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& h, string dir) {
        map<int,int>mp;
        int n= pos.size();
        for(int i=0;i<n;i++){
            mp[pos[i]] = i;
        }
        vector<int> ans;
        stack<int> st;

        for(auto it : mp){
            if(dir[it.second]=='R'){
                st.push(it.second);
            }
            else{
                while(!st.empty() && h[it.second]>0){
                    int ti = st.top();
                    st.pop();
                    if(h[ti]>h[it.second]){
                        h[ti] -= 1;
                        h[it.second] = 0;
                        st.push(ti);
                    }
                    else if (h[ti]<h[it.second]){
                        h[ti] = 0;
                        h[it.second] -= 1;
                    }
                    else{
                        h[ti] = 0;
                        h[it.second] = 0;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            if(h[i]>0) ans.push_back(h[i]);
        }
        return ans;
    }
};