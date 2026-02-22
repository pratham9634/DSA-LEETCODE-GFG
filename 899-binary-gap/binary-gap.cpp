class Solution {
public:
    int binaryGap(int n) {
        int ans = 0;
        int prev = -1;
        int count = 0;
        int num = 1;
        while(num<n){
            if(n & num){
                if(prev!=-1){
                    ans = max(ans,count-prev);
                }
                prev = count;
            }
            num = num << 1;
            count += 1;
        }
        return ans;
    }
};