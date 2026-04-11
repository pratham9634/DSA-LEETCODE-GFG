class Solution {
public:
    string predictPartyVictory(string s) {
        int n = s.length();
        queue<int>qr,qd;

        for(int i=0;i<n;i++){
            if(s[i]=='R')qr.push(i);
            else qd.push(i);
        }
        while(!qr.empty()&&!qd.empty()){
            int idr = qr.front();
            qr.pop();
            int idd = qd.front();
            qd.pop();

            if(idr<idd){
                qr.push(idr+n);
            }
            else qd.push(idd+n);
        }

        return qr.empty()?"Dire":"Radiant";
    }
};