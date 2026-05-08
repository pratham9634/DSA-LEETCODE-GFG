class Solution {
public:
    vector<bool> isPrime;
    
    void build(int mx){
        isPrime.resize(mx+1, true);

        isPrime[0] = false;
        isPrime[1] = false;
        for(int num=2;num*num<=mx;num++){
            if(isPrime[num]) {

                for(int multiple = num*num; multiple <= mx; multiple += num) {
                    isPrime[multiple] = false;
                }
            }
        }
    }
    int minJumps(vector<int>& nums) {
       int n = nums.size();
       unordered_map<int,vector<int>>mp;
       int mx = 0;

       for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
            mx = max(mx, nums[i]);
        } 

        build(mx);

        queue<int>q;
        vector<bool>visited(n,false);
        q.push(0);
        visited[0] = true;

        unordered_set<int> seen;

        int steps = 0;

        while(!q.empty()){
            int size = q.size();

            while(size--){
                int i = q.front();
                q.pop();

                if(i==n-1) return steps;
                if(i-1 >= 0 && !visited[i-1]) {
                    q.push(i-1);
                    visited[i-1] = true;
                }

                if(i+1 <= n-1 && !visited[i+1]) {
                    q.push(i+1);
                    visited[i+1] = true;
                }

                if(!isPrime[nums[i]] || seen.count(nums[i])) {
                    continue;
                }

                for(int x=nums[i];x<=mx;x+=nums[i]){
                    if(!mp.contains(x)) continue;

                    for(int &j : mp[x]) {
                        if(!visited[j]) {
                            q.push(j);
                            visited[j] = true;
                        }
                    }

                }
                seen.insert(nums[i]);
            }
            steps++;
        }

        return steps;
    }
};