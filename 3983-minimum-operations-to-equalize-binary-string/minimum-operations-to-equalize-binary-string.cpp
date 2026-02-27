class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.length();
        int z = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='0') z++;
        }
        if(z==0) return 0;

        vector<int> vec(n+1,-1);
        vec[z] = 0;
        set<int> ev;
        set<int> od;

        for(int i=0;i<=n;i++){
            if(i%2) od.insert(i);
            else ev.insert(i);
        }

        queue<int> q;
        q.push(z);
        if(z%2==1)od.erase(z);
        else ev.erase(z);
        
        while(!q.empty()){
            int t = q.front();
            q.pop();

            int mnf = t + k - 2*min(k,t);
            int mxf = t + k - 2*max(0,k-n+t);
            set<int> &curr = mnf%2==1?od:ev;
            auto it = curr.lower_bound(mnf);

            while(it!=curr.end() && *it <=mxf){
                int nz = *it;
                if(vec[nz] == -1){
                    vec[nz] = vec[t] + 1;
                    if(nz==0) return vec[nz];
                    q.push(nz);
                }
                it = curr.erase(it);
            }
        }


        return -1;
    }
};