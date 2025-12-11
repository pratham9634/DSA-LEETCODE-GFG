class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& b) {
         unordered_map<int, set<int>> mr, mc;
        
        for (auto& b : b) {
            int x = b[0], y = b[1];
            mr[x].insert(y);
            mc[y].insert(x);
        }
        
        int count = 0;
        for (auto& b : b) {
            int x = b[0], y = b[1];
            
            auto it_row = mr[x].lower_bound(y);
            bool lp = (it_row != mr[x].begin()); 
            bool rp = (++it_row != mr[x].end()); 

            auto it_col = mc[y].lower_bound(x);
            bool up = (it_col != mc[y].begin()); 
            bool bp = (++it_col != mc[y].end());
            
            if (lp && rp && up && bp) {
                count++;
            }
        }
        
        return count;
    }
};