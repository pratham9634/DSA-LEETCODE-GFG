class Solution {
public:
    vector<int> parent, rnk;

    int find(int x){
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void Union(int x, int y){
        int px = find(x);
        int py = find(y);

        if(px == py) return;

        if(rnk[px] < rnk[py])
            swap(px, py);

        parent[py] = px;

        if(rnk[px] == rnk[py])
            rnk[px]++;
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();

        parent.resize(n);
        rnk.assign(n, 0);

        for(int i = 0; i < n; i++)
            parent[i] = i;

        for(auto &p : pairs)
            Union(p[0], p[1]);

        unordered_map<int, vector<int>> groups;

        for(int i = 0; i < n; i++){
            groups[find(i)].push_back(i);
        }

        string res = s;

        for(auto &it : groups){
            vector<int> idx = it.second;
            vector<char> chars;

            for(int i : idx)
                chars.push_back(s[i]);

            sort(idx.begin(), idx.end());
            sort(chars.begin(), chars.end());

            for(int i = 0; i < idx.size(); i++){
                res[idx[i]] = chars[i];
            }
        }

        return res;
    }
};