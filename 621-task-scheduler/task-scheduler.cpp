class Solution {
public:
    int leastInterval(vector<char>& tasks, int p) {
        int n = tasks.size();
        if (p == 0) return n;

        vector<int> freq(26, 0);
        for (char &ch : tasks) {
            freq[ch - 'A']++;
        }

        sort(freq.begin(), freq.end());

        int chunks = freq[25] - 1;
        int idle = p * chunks;

        for (int i = 24; i >= 0; i--) {
            idle -= min(chunks, freq[i]);
        }

        idle = max(0, idle); 

        return n + idle;
    }
};