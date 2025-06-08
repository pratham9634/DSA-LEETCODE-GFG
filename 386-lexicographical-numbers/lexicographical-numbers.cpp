class Solution {
public:
    void helper(int crr, int n, vector<int>& ans) {

        if (crr > n) return;
        ans.push_back(crr);

        for (int i = 0; i <= 9; i++) {
            int num = crr * 10 + i;
            if (num > n) return;
            helper(num, n, ans);
        }
    }
    
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for (int i = 1; i <= 9; i++) {
            helper(i, n, ans);
        }
        return ans;
    }
};