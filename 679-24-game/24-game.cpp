class Solution {
public:
    double eps = 0.1;
    bool solve(vector<double>& cards){
        if(cards.size()==1){
            return abs(cards[0]-24)<= eps;
        }
        for(int i=0;i<cards.size();i++){
            for(int j=0;j<cards.size();j++){
                if(i==j) continue;

                vector<double>temp;
                for(int k=0;k<cards.size();k++){
                    if(k!=i && k!=j){
                        temp.push_back(cards[k]);
                    }
                }
                double a = cards[i];
                double b = cards[j];
                vector<double>pv={a+b,a-b,a*b,b-a};

                if(abs(b)>0.0) pv.push_back(a/b);
                if(abs(a)>0.0) pv.push_back(b/a);
                for(double val :pv){
                    temp.push_back(val);
                    if(solve(temp)==true) return true;
                    temp.pop_back();
                }
            }
        }
        return false;
    }
    bool judgePoint24(vector<int>& cards) {
        int n = cards.size();
        vector<double>nums;
        for(int i=0;i<n;i++){
            nums.push_back(1.0*cards[i]);
        }
        return solve(nums);
    }
};