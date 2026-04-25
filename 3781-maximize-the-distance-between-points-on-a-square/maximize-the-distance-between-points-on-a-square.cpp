class Solution {
public:
    bool check(long long l,vector<long long>&vec,int side,int k){
        for(long long st :vec){
            long long end = st+side*4LL-l;
            long long curr = st;
            for(int i=0;i<k-1;i++){
                auto it = ranges::lower_bound(vec,curr+l);
                if(it==vec.end()||*it>end){
                    curr= -1;
                    break;
                }
                curr = *it;
            }
            if(curr>=0) return true;
        }
        return false;
    }
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long>v;
        for(auto &p : points){
            long long x = p[0];
            long long y = p[1];

            if(x==0){
                v.push_back(y);
            }else if(y==side){
                v.push_back(side+x);
            }else if(x==side){
                v.push_back(side*3LL-y);
            }else{
                v.push_back(side*4LL-x);
            }
        }
        sort(v.begin(),v.end());
        int ans = 0;
        long long lo = 1,hi=side;
        while(lo<=hi){
            long long mid = (lo+hi)/2;
            if(check(mid,v,side,k)){
                lo = mid +1;
                ans = mid;
            }else{
                hi = mid-1;
            }
        }
        return ans;
    }
};