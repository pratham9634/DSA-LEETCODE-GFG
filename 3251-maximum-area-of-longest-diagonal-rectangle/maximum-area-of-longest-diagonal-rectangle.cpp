class Solution {
public:
    int area(int l,int b){
        return (l*l+b*b);
    }
    int areaOfMaxDiagonal(vector<vector<int>>& d) {
        int n = d.size();
        int ans = 0,res =0;
        for(int i=0;i<n;i++){
            int l = d[i][0];
            int b = d[i][1];

            int a = area(l,b);
            if(a>ans) res = l*b;
            ans = max(ans,a);
            if(a==ans) res = max(res,l*b);
        }
        return res;
    }
};