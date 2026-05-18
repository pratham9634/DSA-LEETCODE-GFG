class Solution {
public:
    int solve(vector<int>& arr, int& n){
        vector<bool> vis(n,false);
        unordered_map<int,vector<int>>mp;

        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        queue<int>q;
        q.push(0);
        vis[0] = true;
        int ans = 0;
        while(!q.empty()){
            int size = q.size();

            while(size--){
                int curr = q.front();q.pop();
                if(curr==n-1) return ans;
                int left = curr - 1;
            int right = curr + 1;

            if(left>0 && !vis[left]){
                q.push(left);
                vis[left] = true;
            }
            if(right<n && !vis[right]){
                q.push(right);
                vis[right] = true;
            }

            for(const int &idx : mp[arr[curr]]) {
                    if(!vis[idx]) {
                        q.push(idx);
                        vis[idx] = true;
                    }
            }
                
            mp.erase(arr[curr]);
            }
            ans++;
        }
        return -1;
    }
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n == 1)
            return 0;
        return solve(arr, n);
    }
};