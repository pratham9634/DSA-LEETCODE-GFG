class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr)
        {
            return 0;
        }
        queue<pair<TreeNode*,long long>>q;
        long long mw=0;
        q.push({root,0});
        while(!q.empty())
        {
            int n=q.size();
            long long first=q.front().second;
            long long last=q.back().second;
            mw=max(mw,last-first+1);
            for(int i=0;i<n;i++)
            {
             auto curr=q.front();
             q.pop();
             long long in=curr.second-first;
              if(curr.first->left)
              {
                q.push({curr.first->left,2*in+1});
              }
              if(curr.first->right)
              {
                q.push({curr.first->right,(2*in+2)});
              }
            }
        }
        return mw;
    }
};