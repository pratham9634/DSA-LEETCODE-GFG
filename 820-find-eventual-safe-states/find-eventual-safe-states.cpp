class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        int n = g.size();
        vector<vector<int>> vec(n);
        vector<int> o(n), s(n), ans;
        queue<int> q;

        for(int i=0;i<n;i++){
            for(int v : g[i]){
                vec[v].push_back(i);
            }
            o[i] = g[i].size();
            if(o[i]==0) q.push(i);
        }
        while (q.size()) {

            int u = q.front();
            q.pop();
            s[u] = 1;
            for (int v : vec[u]) {
              if (--o[v] == 0) q.push(v);
            }
        }

        for (int i = 0; i < n; ++i) {
           if (s[i]) ans.push_back(i);
        }
        return ans;

    }
};