class Solution {
public:
    bool check(int x){
        if(x==2||x==5||x==6||x==9) return true;
        return false;
    }
    bool invalid(int x){
        if(x==3||x==4||x==7) return true;
        return false;
    }
    int rotatedDigits(int n) {
        int ans = 0;

        for(int i=2;i<=n;i++){
            int num = i;
            bool flag = false;
            while(num){
                int rem = num%10;
                if(invalid(rem)){
                    flag = false;
                    break;
                }
                if(check(rem)){
                     flag = true;
                }
                num = num/10;
            }
            if(flag) ans++;
        }

        return ans;
    }
};