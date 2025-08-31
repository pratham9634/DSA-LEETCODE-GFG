class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        int n = c.size();
        
        // prefix sum from front
        vector<int> prefix(k+1, 0);
        for(int i=0; i<k; i++){
            prefix[i+1] = prefix[i] + c[i];
        }
        
        // suffix sum from back
        vector<int> suffix(k+1, 0);
        for(int i=0; i<k; i++){
            suffix[i+1] = suffix[i] + c[n-1-i];
        }
        
        int ans = 0;
        for(int i=0; i<=k; i++){
            ans = max(ans, prefix[i] + suffix[k-i]);
        }
        return ans;
    }
};
