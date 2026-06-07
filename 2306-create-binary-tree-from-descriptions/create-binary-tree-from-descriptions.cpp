class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& des) {
        unordered_map<int, TreeNode*> map;
        
        for (auto& arr : des) {
            int parent = arr[0], child = arr[1], isLeft = arr[2];
            
            if (map.find(parent) == map.end()) {
                map[parent] = new TreeNode(parent);
            }
            if (map.find(child) == map.end()) {
                map[child] = new TreeNode(child);
            }
            
            if (isLeft == 1) {
                map[parent]->left = map[child];
            } else {
                map[parent]->right = map[child];
            }
        }
        
        for (auto& pair : map) {
            bool isChild = false;
            for (auto& arr : des) {
                if (pair.first == arr[1]) {
                    isChild = true;
                    break;
                }
            }
            if (!isChild) {
                return pair.second;
            }
        }
        return nullptr;
    }
};