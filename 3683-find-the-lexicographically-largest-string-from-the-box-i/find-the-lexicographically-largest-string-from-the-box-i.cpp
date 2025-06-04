class Solution {
public:
    string answerString(string word, int f) {
        if(f==1) return word;
        int n = word.length();
        vector<string> ans;
        for(int i =0;i<n;i++){

                ans.push_back(word.substr(i,n-f+1));

        }
        sort(ans.begin(),ans.end());
        return ans[ans.size()-1];
    }
};