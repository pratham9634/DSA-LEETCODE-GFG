class Solution {
public:
    int maxDistance(vector<int>& c) {
        int n = c.size();
        int ans = 0;
        int i=0,j=n-1;
        while(i<j){
            if(c[i]!=c[j]){
                ans = max(ans,j-i);
                break;
            }
            else{
                i++;
            }
        }
        i=0,j=n-1;
        while(i<j){
            if(c[i]!=c[j]){
                ans = max(ans,j-i);
                break;
            }
            else{
                j--;
            }
        }

        return ans;
    }
};