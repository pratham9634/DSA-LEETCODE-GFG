class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* prev;
        TreeNode* curr = root;
        while(curr!=NULL){
            if(curr->left==NULL){
                ans.push_back(curr->val);
                curr = curr->right;
            }else{
                prev = curr->left;
                while(prev->right){
                    prev = prev->right;
                }
                prev->right = curr;
                TreeNode* temp = curr;
                curr = curr->left;
                temp->left = NULL;
            }
        }
        return ans;
    }
};