class Solution {
public:
    TreeNode* recoverFromPreorder(string s) {
        stack<pair<TreeNode*, int>> st;
        int i = 0, n = s.length();

        while (i < n) {
            int depth = 0;
            while (i < n && s[i] == '-') {
                depth++;
                i++;
            }

            int num = 0;
            while (i < n && isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }

            TreeNode* node = new TreeNode(num);

            while (!st.empty() && st.top().second >= depth) {
                st.pop();
            }

            if (!st.empty()) {
                TreeNode* parent = st.top().first;
                if (!parent->left)
                    parent->left = node;
                else
                    parent->right = node;
            }

            st.push({node, depth});
        }

        while (st.size() > 1) st.pop();
        return st.top().first;
    }
};
