class Solution {
public:
    int helper(int curr, int p, const vector<vector<int>>& adj, const vector<int>& values, int k, int &c) {
        int sum = 0;
        for (auto neighbour : adj[curr]) {
            if (neighbour != p) {
                sum += helper(neighbour, curr, adj, values, k, c);
                sum %= k;
            }
        }
        sum += values[curr];
        sum %= k;
        if (sum == 0) c++;
        return sum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for (auto edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];
            adj[node1].push_back(node2);
            adj[node2].push_back(node1);
        }
        int c = 0;
        helper(0, -1, adj, values, k, c);
        return c;
    }
};