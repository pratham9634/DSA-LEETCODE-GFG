class Solution {
public:
    vector<int>stree;
    int n = 50000;

    void construct(){
        stree.resize(4*n,0);
    }

    void update(int idx, int val, int i, int l, int r){
        if(l==r){
            stree[i] = val;
            return;
        }

        int mid = l + (r-l)/2;

        if(idx<=mid){
            update(idx, val, 2*i+1, l, mid);
        }else{
             update(idx, val, 2*i+2, mid+1, r);
        }
        stree[i] = max(stree[2*i+1],stree[2*i+2]);
    }

    int query(int start, int end, int i, int l, int r) {
         if(l > end || r < start) { //out of range node hai ye, return kar jao
            return 0;
        }

        if(l >= start && r <= end) {
            return stree[i];
        }

        int mid = l + (r-l)/2;

        return max(query(start, end, 2*i+1, l, mid), query(start, end, 2*i+2, mid+1, r));
    }

    vector<bool> getResults(vector<vector<int>>& queries) {
        construct();
        set<int>st;
        st.insert(0);
        vector<bool>ans;

        for(auto& q : queries){
            if(q[0]==1){
                int x = q[1];

                auto it = st.upper_bound(x);
                int nxt = (it != st.end())?*it:-1;
                int pre = *prev(it);

                update(x,x-pre,0,0,n-1);
                if(nxt!=-1) update(nxt,nxt-x,0,0,n-1);

                st.insert(x);
            }
            else{
                int x = q[1];
                int sz = q[2];

                auto it = st.upper_bound(x);
                int pre = *prev(it);

                int mgap = query(0,pre,0,0,n-1);
                int best = max(mgap,x-pre);

                ans.push_back(best>=sz);
            }
        }
        return ans;
    }
};