
class Solution {
public:
    int ans =0;
    int solve(TreeNode* root,int s){
        int d = 0;
        if(!root) return d;

        int ld = solve(root->left,s);
        int rd = solve( root->right,s);

        if(root->val==s){
            ans = max(ld,rd);
            d = -1;
        }
        else if(ld>=0 && rd>=0){
            d = max(ld,rd)+1;
        }
        else{
            int dist = abs(ld)+abs(rd);
            ans = max(dist,ans);
            d = min(ld,rd)-1;
        }
        return d;
    }
    int amountOfTime(TreeNode* root, int start) {
         solve(root,start);
         return ans;
    }
};