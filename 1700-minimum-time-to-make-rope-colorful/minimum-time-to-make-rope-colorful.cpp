class Solution {
public:
    int minCost(string c, vector<int>& nt) {
        int ans = 0;
        priority_queue<int> pq;
        pq.push(nt[0]);
        int sum = nt[0];
        
        for (int i = 1; i < c.size(); i++) {
            if (c[i] == c[i-1]) {
                pq.push(nt[i]);
                sum += nt[i];
            } else {
                ans += sum - pq.top();
                while (!pq.empty()) pq.pop();
                pq.push(nt[i]);
                sum = nt[i];
            }
        }
        ans += sum - pq.top();
        return ans;
    }
};
