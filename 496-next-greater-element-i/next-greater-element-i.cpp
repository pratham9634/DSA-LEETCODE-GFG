class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        int m = nums1.size();
        stack<int> st;
        unordered_map<int,int>mp;
        vector<int> ans(m,0);

        for(int i=n-1;i>=0;i--){
            if(st.empty()) mp[nums2[i]] = -1;
            else{
                while(!st.empty()&&st.top()<nums2[i]){
                    st.pop();

                }
                if(st.empty()) mp[nums2[i]] = -1;
                else mp[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }
        for(int i=0;i<m;i++){
            ans[i] = mp[nums1[i]];
        }
        return ans;
    }
};