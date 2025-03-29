class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        if (k == 0) return vector<int>(edges1.size() + 1, 1);

        int n1 = edges1.size() + 1, n2 = edges2.size() + 1;
        vector<vector<int>> adjacencyList1(n1), adjacencyList2(n2);

        for (auto& edge : edges1) {
            adjacencyList1[edge[0]].push_back(edge[1]);
            adjacencyList1[edge[1]].push_back(edge[0]);
        }
        for (auto& edge : edges2) {
            adjacencyList2[edge[0]].push_back(edge[1]);
            adjacencyList2[edge[1]].push_back(edge[0]);
        }

        auto calculateReachableNodes_BFS = [](vector<vector<int>>& adjacencyList, int maxDistance) {
            int n = adjacencyList.size();
            vector<int> reachCounts(n, 0);
            
            for (int startNode = 0; startNode < n; ++startNode) {
                vector<bool> visited(n, false);
                queue<int> q;
                q.push(startNode);
                visited[startNode] = true;
                int level = 0;

                while (!q.empty() && level < maxDistance) {
                    int lenQ = q.size();
                    ++level;

                    for (int i = 0; i < lenQ; ++i) {
                        int currentNode = q.front();
                        q.pop();
                        
                        for (int neighbor : adjacencyList[currentNode]) {
                            if (!visited[neighbor]) {
                                visited[neighbor] = true;
                                q.push(neighbor);
                            }
                        }
                    }
                }
                reachCounts[startNode] = count(visited.begin(), visited.end(), true);
            }
            return reachCounts;
        };

        vector<int> reachableCount1 = calculateReachableNodes_BFS(adjacencyList1, k);
        vector<int> reachableCount2 = calculateReachableNodes_BFS(adjacencyList2, k - 1);

        int maxReachableInTree2 = *max_element(reachableCount2.begin(), reachableCount2.end());
        
        for (int i = 0; i < reachableCount1.size(); ++i) {
            reachableCount1[i] += maxReachableInTree2;
        }

        return reachableCount1;
    }
};