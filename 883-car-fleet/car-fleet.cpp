class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& sp) {
        int n = pos.size();
        vector<pair<int,int>> cars;

        for(int i = 0; i < n; i++) {
            cars.push_back({pos[i], sp[i]});
        }

        sort(cars.begin(), cars.end());

        stack<double> st;

        for(int i = n - 1; i >= 0; i--) {
            double time = (double)(target - cars[i].first) / cars[i].second;

            if(st.empty() || time > st.top()) {
                st.push(time);
            }
        }

        return st.size();
    }
};