class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int, map<int, multiset<int>>> mp;
        queue<tuple<TreeNode*, int, int>> q; 
        q.push({root, 0, 0});
        
        while (!q.empty()) {
            auto [node, hd, lvl] = q.front();
            q.pop();
            
            mp[hd][lvl].insert(node->val);
            
            if (node->left)  q.push({node->left, hd-1, lvl+1});
            if (node->right) q.push({node->right, hd+1, lvl+1});
        }
        
        vector<vector<int>> ans;
        for (auto &p : mp) {            // iterate over hd
            vector<int> col;
            for (auto &q : p.second) { // iterate over levels
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};
