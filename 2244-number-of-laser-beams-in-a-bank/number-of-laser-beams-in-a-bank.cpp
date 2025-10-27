class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int tb = 0;
        int pb = 0;
        for (int i = 0; i < bank.size(); i++) {
            int cb = 0;
            for (int j = 0; j < bank[i].size(); j++) {
                if (bank[i][j] == '1') {
                    cb++;
                }
            }
            if (cb > 0) {
                tb += pb * cb;
                pb = cb;
            }
        }
        return tb;
    }
};