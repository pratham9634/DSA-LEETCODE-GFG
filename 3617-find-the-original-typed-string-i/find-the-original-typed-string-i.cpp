class Solution {
public:
    int possibleStringCount(string word) {
         int c =0;
        char x =word[0];
    int n = word.length();
        for(int i=1;i<n;i++)
            {
                if(x==word[i]) c++;
                x=word[i];
            }
    return c+1;
    }
};