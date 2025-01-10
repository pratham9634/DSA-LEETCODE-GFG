class Solution {
public:
    vector<string> wordSubsets(vector<string>& w1, vector<string>& w2) {
        unordered_map<char, int> maxFreq;
        
        for (const string& word : w2) {
            unordered_map<char, int> currentFreq;
            for (char c : word) {
                currentFreq[c]++;
            }
            for (const auto& entry : currentFreq) {
                maxFreq[entry.first] = max(maxFreq[entry.first], entry.second);
            }
        }

        vector<string> ans;
        
        for (const string& word : w1) {
            unordered_map<char, int> wordFreq;
            for (char c : word) {
                wordFreq[c]++;
            }
            
            bool isUniversal = true;
            for (const auto& entry : maxFreq) {
                if (wordFreq[entry.first] < entry.second) {
                    isUniversal = false;
                    break;
                }
            }
            
            if (isUniversal) {
                ans.push_back(word);
            }
        }
        
        return ans;
    }
};