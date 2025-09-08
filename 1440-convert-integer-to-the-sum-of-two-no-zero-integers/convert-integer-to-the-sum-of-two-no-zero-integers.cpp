class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int a = n;
        int b = 0;
        int tv = 1;

        while(n>1){
            int take = 1;
            if(n%10==1) take =2;
            a = a - take*tv;
            b = b + take*tv;

            n = (n - take)/10;
            tv *= 10; 
        }
        return {a,b};
    }
};