class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(start);

        while (!q.empty()) {
            int x = q.front();
            q.pop();

            if (arr[x] == 0) return true;

            visited[x] = true;

            int forward = x + arr[x];
            int backward = x - arr[x];

            if (forward < n && !visited[forward]) {
                q.push(forward);
                visited[forward] = true;
            }

            if (backward >= 0 && !visited[backward]) {
                q.push(backward);
                visited[backward] = true;
            }
        }

        return false;
    }
};