class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        map<int, int> freqCount;

        for (int n : arr) {
            mp[n]++;
        }

        for (auto& p : mp) {
            freqCount[p.second]++;  
        }

        int uniqueCount = mp.size(); 

        for (auto& p : freqCount) {
            int freq = p.first;  
            int count = p.second;  

            int removeCount = min(count, k / freq);
            k -= removeCount * freq;
            uniqueCount -= removeCount;

            if (k < freq) break;
        }

        return uniqueCount;
    }
};