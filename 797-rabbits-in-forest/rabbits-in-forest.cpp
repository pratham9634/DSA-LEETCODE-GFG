class Solution {
public:
    int numRabbits(vector<int>& ans) {
        sort(ans.begin(),ans.end());
        int sum=0;
        int cnt=0;
        for(int i=0;i<ans.size();i++){
            if(ans[i]!=0){
            
            if(ans[i+1]==ans[i] && cnt+1<=ans[i]) {
                cnt++;
                continue;
            }
            else cnt=0;
           sum+= ans[i]+1;
            }
            else sum++;
        }
        return sum;
    }
};