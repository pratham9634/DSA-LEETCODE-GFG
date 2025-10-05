class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();

        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';

        int steps = 0;
        vector<pair<int, int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [x, y] = q.front();
                q.pop();

                for (auto [dx, dy] : directions) {
                    int nx = x + dx;
                    int ny = y + dy;

                    if (nx >= 0 && ny >= 0 && nx < m && ny < n && maze[nx][ny] == '.') {
                        if (nx == 0 || ny == 0 || nx == m - 1 || ny == n - 1)
                            return steps + 1;

                        maze[nx][ny] = '+'; 
                        q.push({nx, ny});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
