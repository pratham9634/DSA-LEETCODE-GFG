class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans;
    for(int i = 0, last = -1; i < words.size(); ++i){
        if(last == groups[i]) continue;
        last = groups[i];
        ans.push_back(words[i]);
    }
    return ans;
    }
};