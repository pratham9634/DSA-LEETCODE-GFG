
class Solution {
public:
    TreeNode* solve(vector<int>&arr,int l,int r){
        if(l>=r) return NULL;
        int val = arr[l];
        TreeNode* node = new TreeNode(val);
        int idx = r;
        for(int i=l+1;i<r;i++){
            if(arr[i]>arr[l]){
                idx = i;
                break;
            }
        }
        node->left = solve(arr,l+1,idx);
        node->right = solve(arr,idx,r);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int rval = preorder[0];
        int n = preorder.size();
        int i = 0;
        while(i<n){
            if(preorder[i]>rval) break;
            i++;
        }
        TreeNode* root = new TreeNode(rval);
        root->left = solve(preorder,1,i);
        root->right = solve(preorder,i,n);
        return root;
    }
};