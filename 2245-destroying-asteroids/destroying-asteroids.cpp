class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& ast) {
        sort(begin(ast),end(ast));
        long long m = mass;
        for(int a : ast){
            if(m<a) return false;
            m += a;
        }
        return true;
    }
};