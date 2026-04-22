class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dict) {
        vector<string>ans;
        for(string& q : queries){
            for(string& s : dict){
                int diff = 0;
                for(int i=0;i<q.size();i++){
                    if(q[i]!=s[i]){
                        ++diff;
                    }
                    if(diff>2){
                        break;
                    }
                }
                if(diff<=2){
                    ans.push_back(q);
                    break;
                }
            }
        }
        return ans;
    }
};