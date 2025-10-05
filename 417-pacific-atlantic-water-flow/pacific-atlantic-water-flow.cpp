class Solution {
public:
    int m,n;
    vector<vector<int>> direction = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        m = h.size();
        n = h[0].size();

        vector<vector<bool>> p(m,vector<bool>(n,false));
        vector<vector<bool>> a(m,vector<bool>(n,false));

        for(int i=0;i<m;i++) dfs(i,0,h,p);
        for(int j = 0;j<n;j++) dfs(0,j,h,p);

        for(int i=0;i<m;i++) dfs(i,n-1,h,a);
        for(int j = 0;j<n;j++) dfs(m-1,j,h,a);

        vector<vector<int>> ans;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(p[i][j] && a[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
    void dfs(int i,int j,vector<vector<int>> &h,vector<vector<bool>> &vis){
        vis[i][j] = true;
        for(auto &d : direction){
            int x = i+d[0];
            int y = j+d[1];
            if(x<0||x>=m||y<0||y>=n) continue;
            if(vis[x][y]) continue;
            if(h[i][j]>h[x][y]) continue;
            dfs(x,y,h,vis);
        }
    }
};