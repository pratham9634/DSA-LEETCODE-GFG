class Solution {
public:
    vector<int> rank;
    vector<int> parent;

    int find(int x){
        if(parent[x]!=x){
            parent[x] = find(parent[x]);
        }
        return parent[x] ;
    }
    void Union(int x,int y){
        int px = find(x);
        int py = find(y);

        if(py==px) return;

        if(rank[px]<rank[py]){
            swap(px,py);
        }
        parent[py] = px;

        if(rank[px]==rank[py]){
            rank[px]++;
        }
    }
    int minimumHammingDistance(vector<int>& s, vector<int>& t, vector<vector<int>>& as) {
        int n = s.size();

        parent.resize(n);
        rank.resize(n, 0);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for(auto& vec : as){
            Union(vec[0],vec[1]);
        }

        unordered_map<int,unordered_map<int,int>> mp;

        for(int i=0;i<n;i++){
            int curr = s[i];

            int parent = find(i);
            mp[parent][curr]++;
        }
        int ans = 0;
        for(int i=0;i<n;i++){

            int parent = find(i);

           if(mp[parent][t[i]]>0){
            mp[parent][t[i]]--;
           }
           else ans++;
        }
        return ans;
    }
};