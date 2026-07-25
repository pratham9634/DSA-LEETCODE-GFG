class Solution {
public:
    int maxProduct(int n) {
        vector<int> dig;
        int k = n;

        while(k){
            int rem = k % 10;
            k = k/10;
            dig.push_back(rem);
        }

        sort(dig.begin(),dig.end());
        int s = dig.size();

        return dig[s-2]*dig[s-1];
    }
};