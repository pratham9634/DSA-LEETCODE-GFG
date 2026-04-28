
class BSTIterator {
    TreeNode* curr;
public:

    BSTIterator(TreeNode* root) {
       curr = root;
    }
    
    int next() {
        int ans = -1;
        while (curr) {
            if (!curr->left) {
                ans = curr->val;
                curr = curr->right;
                break;
            } else {
                TreeNode* pred = curr->left;
                while (pred->right && pred->right != curr) {
                    pred = pred->right;
                }

                if (!pred->right) {
                    pred->right = curr;
                    curr = curr->left;
                } else {
                    pred->right = NULL;
                    ans = curr->val;
                    curr = curr->right;
                    break;
                }
            }
        }

        return ans;
    }
    
    bool hasNext() {
        return curr != NULL;
    }
};

