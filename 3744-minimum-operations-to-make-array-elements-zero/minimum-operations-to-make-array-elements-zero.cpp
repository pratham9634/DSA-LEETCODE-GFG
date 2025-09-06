class Solution {
public: 
    long long solve(int l,int r){
        long long L = 1;
        long long S = 1;
        long long step = 0;

        while(L<=r){
            long long R = 4*L-1;
            long long st = max(L,(long long)l);
            long long en = min(R,(long long)r); 
            if(st<=en){
                step += (en-st+1)*S; 
            }
            S+=1;
            L=4*L;
        }
        return step;
    }
    long long minOperations(vector<vector<int>>& q) {
        int n = q.size();
        long long ans =0;

        for(int i=0;i<n;i++){
            int l = q[i][0];
            int r = q[i][1];
            ans+=(solve(l,r)+1)/2;
        }
        return ans;
    }
};
