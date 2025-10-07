class Solution {
public:
    vector<int> avoidFlood(vector<int>& r) {
         int n = r.size();
        vector<int> ans(n, -1);
        unordered_map<int, int> full; 
        set<int> dryDays;            

        for (int i = 0; i < n; i++) {
            if (r[i] == 0) {
                dryDays.insert(i);   
                ans[i] = 1;         
            } else {
                int lake = r[i];
                if (full.find(lake) != full.end()) {
                    auto it = dryDays.lower_bound(full[lake]);
                    if (it == dryDays.end()) return {};
                    ans[*it] = lake; 
                    dryDays.erase(it);   
                }
                full[lake] = i; 
            }
        }
        return ans;
    }
};