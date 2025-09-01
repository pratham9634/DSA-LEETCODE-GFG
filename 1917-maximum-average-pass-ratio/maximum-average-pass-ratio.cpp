class Solution {
public:
    #define P pair<double,int>
    double maxAverageRatio(vector<vector<int>>& c, int e) {
        int n = c.size();
        priority_queue<P> pq;

        for(int i=0;i<n;i++){
            double cpr = (double)c[i][0]/c[i][1];
            double npr = (double)(c[i][0]+1)/(c[i][1]+1);
            double delta = npr-cpr;
            pq.push({delta,i});
        }

        while(e--){
            auto curr = pq.top();
            pq.pop();

            double delta = curr.first;
            int idx = curr.second;

            c[idx][0]++;
            c[idx][1]++;
            double cpr = (double)c[idx][0]/c[idx][1];
            double npr = (double)(c[idx][0]+1)/(c[idx][1]+1);
            double delt = npr-cpr;
            pq.push({delt,idx});
        }
        double result =0.0;
        for(int i=0;i<n;i++){
            result+=(double)c[i][0]/c[i][1];
        }
        return result/n;
    }
};