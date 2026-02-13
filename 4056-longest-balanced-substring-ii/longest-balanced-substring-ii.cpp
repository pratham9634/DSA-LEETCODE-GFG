class Solution {
public:
    int solve1(string s,char x, char y){
        int c1= 0,c2=0;
        unordered_map<int,int> mp;
int ans = 0;
        for(int i=0;i<s.length();i++){
            
            if(s[i]!=x && s[i]!=y){
                mp.clear();
                c1 = 0;
                c2 = 0;
                continue;
            }
            if(s[i]==x) c1++;
            if(s[i]==y) c2++;
            if(c1 == c2 ){
                ans= max(ans,c1+c2);
            }
            

            int d = c1 - c2;
            if(mp.count(d)){
                ans = max(ans,i-mp[d]);
            }
            else mp[d] = i;
        }
        return ans;
    }
    int solve2(string s){
        int c1 =0,c2=0,c3=0;
        int ans = 0;
        unordered_map<string,int> mp;

        for(int i=0;i<s.length();i++){

            if(s[i]=='a') c1++;
            if(s[i]=='b') c2++;
            if(s[i]=='c') c3++;

            if(c1==c2 && c1==c3){
                ans = max(ans,3*c1);
            }

            int dab = c1 - c2;
            int dac = c1 - c3;

            string key = to_string(dab) + "_" + to_string(dac);
            if(mp.count(key)){
                ans = max(ans,i-mp[key]);
            }else mp[key] = i;
        }
        return ans;
    }
    int longestBalanced(string s) {
        int n = s.length();
        int ans = 1;

        //case1
        int count = 1;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                count++;
            }
            else{
                ans = max(ans ,count);
                count = 1;
            }
        }
        ans = max(ans ,count);

        //case2 

        ans = max(ans,solve1(s,'a','b'));
        ans = max(ans,solve1(s,'a','c'));
        ans = max(ans,solve1(s,'b','c'));

        //case3

        ans = max(ans,solve2(s));

        return ans;
    }
};