class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int ans = 0;
        int msum = INT_MIN;

        queue<TreeNode*>q;

        q.push(root);
        int l = 1;
        while(!q.empty()){
            int size = q.size();
            int csum = 0;
            for(int i=0;i<size;i++){
                TreeNode* top = q.front();
                q.pop();
                csum+=top->val;
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
            if(csum>msum){
                msum = csum;
                ans = l;
            }
            l++;
        }
        return ans;
    }
};