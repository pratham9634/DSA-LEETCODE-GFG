
class Solution {
public:
    void solve(Node* root,Node* a){
        if(!root) return;
        root->next = a;
        if(root->left) solve(root->left,root->right);
        if(root->right) solve(root->right,a?a->left:NULL);
    }
    Node* connect(Node* root) {
        solve(root,NULL);
        return root;
    }
};