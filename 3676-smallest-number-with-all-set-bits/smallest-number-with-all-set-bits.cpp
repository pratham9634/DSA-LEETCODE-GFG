class Solution {
public:
    int smallestNumber(int n) {
        int c = 0;
       while(n){
        n = n/2;
        c++;
       } 
       return pow(2,c) - 1;
    }
};