class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& q) {
        vector<vector<int>> ans(n, vector<int>(n,0)); 
        for(int i = 0;i<q.size();i++){
            for(int x =q[i][0];x<=q[i][2];x++){
                for(int y =q[i][1];y<=q[i][3];y++){
                    ans[x][y]++;
                }
            }
        }
        return ans;
    }
};