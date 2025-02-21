class FindElements {
public:
    unordered_map<int,int> mp;
    void helper(TreeNode* root,int x,unordered_map<int,int> &mp){
        if(root==NULL) return;
        root->val=x;
        mp[x]++;
        if(root->left) helper(root->left,2*x+1,mp);
        if(root->right) helper(root->right,2*x+2,mp);
    }
    FindElements(TreeNode* root) {
        helper(root,0,mp);
    }
    
    bool find(int target) {
        if(mp.find(target)!=mp.end()) return true;
        return false;
    }
};