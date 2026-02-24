
class Solution {
public:
    vector<string> vec;
    void solve(TreeNode* root,string s){
        if(!root) return ;

        s += to_string(root->val);
        if(!root->left &&!root->right){
            vec.push_back(s);
            return;
        }
        if(root->left) solve(root->left,s);
        if(root->right) solve(root->right,s);
    }
    int helper(string s){
        reverse(s.begin(),s.end());
        int sum = 0;
        for(int i=0;i<s.length();i++){
            sum += s[i]=='1'?pow(2,i) : 0;
        }
        return sum;
    }
    int sumRootToLeaf(TreeNode* root) {
        solve(root,"");
        int sum = 0;
        for(int i=0;i<vec.size();i++){
            sum+=helper(vec[i]);
        }
        return sum;
    }
};