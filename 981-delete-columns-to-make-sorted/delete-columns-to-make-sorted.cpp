class Solution {
public:
    int minDeletionSize(vector<string>& s) {
        int r = s.size();
        int c = s[0].size();
        int ans = 0;
        for(int j = 0;j<c;j++){
            for(int i=0;i<r-1;i++){
                if(s[i][j]>s[i+1][j]){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};