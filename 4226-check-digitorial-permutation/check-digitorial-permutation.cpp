class Solution {
public:
    vector<int> fact = {1,1,2,6,24,120,720,5040,40320,362880};
    bool isDigitorialPermutation(int n) {
        vector<int> freq(10,0);
        int temp = n;
        while(temp){
            int rem = temp%10;
            freq[rem]++;
            temp/=10;
        }
        int sum = 0;
        while(n){
            int rem = n%10;
            sum += fact[rem];
            n = n/10;
        }
         while(sum){
            int rem = sum%10;
            freq[rem]--;
            sum/=10;
        }
        for(int i=0;i<10;i++){
            if(freq[i]!=0) return false;
        }
        return true;
    }
};