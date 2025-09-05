class Solution {
public:
    int t[1001][1001];
    int solve(int curr,int clip,int n){
        if(curr==n) return 0;
        if(curr>n) return 100000;
        if(t[curr][clip]!=-1) return t[curr][clip];
        int cp = 1+1+solve(curr+curr,curr,n);
        int p = 1+solve(curr+clip,clip,n);

        return t[curr][clip]=min(cp,p);
    }
    int minSteps(int n) {
        if(n==1) return 0;
        memset(t,-1,sizeof(t));
        return 1+solve(1,1,n);
    }
};