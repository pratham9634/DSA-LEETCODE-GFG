class Solution {
public:
    bool checkStrings(string s1, string s2) {
        string x1 = "",x2 = "",y1="",y2="";
        for(int i=0;i<s1.size();i++){
            if(i%2==1){
                x2+=s1[i];
                y2+=s2[i];
            }
            else{
                x1+=s1[i];
                y1+=s2[i];
            }
        }
        sort(x1.begin(),x1.end());
        sort(x2.begin(),x2.end());
        sort(y1.begin(),y1.end());
        sort(y2.begin(),y2.end());

        return ((x1==y1)&&(x2==y2));
    }
};