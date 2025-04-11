class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for(int i=low;i<=high;i++){
            int sum = 0;
            string s = to_string(i);
            if(s.length()%2==1)continue;
            for(int j=0;j<s.length()/2;j++){
                sum+= s[j]-'0';
                sum-=s[s.length()-j-1] -'0';
            }
            if(sum==0) count++;
        }
        return count;
    }
};