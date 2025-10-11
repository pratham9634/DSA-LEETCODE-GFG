
class Solution {
public:
    TreeNode* solve(vector<int>& in,int inl,int inh , vector<int>& pos,int posl,int posh){
        if(inl>inh || posl>posh) return NULL;
        TreeNode *root = new TreeNode(pos[posh]);
        if(inl==inh) return root;
        int i = inl;
        while(i<=inh){
            if(in[i]==pos[posh]) break;
            i++;
        }
        int lc = i-inl;
        int rc = inh-i;
        root->left = solve(in,inl,i-1,pos,posl,posl+lc-1);
        root->right = solve(in,i+1,inh,pos,posl+lc,posh-1);
        return root;


    }
    TreeNode* buildTree(vector<int>& in, vector<int>& pos) {
        int  n = in.size();
        return solve(in,0,n-1,pos,0,n-1);
    }
};