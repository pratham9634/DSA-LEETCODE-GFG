class Solution {
public:
    struct Node{
        int count;
        Node* child[26];

        Node(){
            count = 0;
            for(int i=0;i<26;i++) child[i]=NULL;
        }
    };
    void insert(Node* root,string w){
        Node* p  = root;
        int n = w.size();
        for(int i=0;i<n;i++){
            int ch = w[i] - 'a';
            if(p->child[ch]==NULL){
                p->child[ch] = new Node();
            }
            p = p->child[ch];
            p->count++;
        }
    }

    int search(Node* root,string w){
         Node* p  = root;
        int n = w.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            int ch = w[i] - 'a';
            p = p->child[ch];
            ans+=p->count;
        }
        return ans;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        Node* root = new Node();

        for(string s : words){
            insert(root,s);
        }
        vector<int> ans(words.size(),0);

        for(int i=0;i<words.size();i++){
            ans[i] = search(root,words[i]);
        }
        return ans;
    }
};