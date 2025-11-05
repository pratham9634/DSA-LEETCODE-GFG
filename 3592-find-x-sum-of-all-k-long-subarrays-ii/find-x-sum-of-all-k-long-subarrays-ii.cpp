class Solution {
public:
    long long sum=0;
    set<pair<int,int>>m;
    set<pair<int,int>>sec;

    void is(pair<int,int> p,int x){
        if(m.size()<x || p>*m.begin()){
            sum += 1LL*p.first*p.second;
            m.insert(p);
            if(m.size()>x){
                auto sm = *m.begin();
                sum -= 1LL*sm.first*sm.second;
                m.erase(sm);
                sec.insert(sm);
            }
        }else {
            sec.insert(p);
        }
    }
    void rs(pair<int,int>p,int x){
        if(m.find(p)!=m.end()){
            sum -= 1LL*p.first*p.second;
            m.erase(p);

            if(!sec.empty()){
                auto lg = *sec.rbegin();
                sec.erase(lg);
                m.insert(lg);
                sum += 1LL*lg.first*lg.second;
            }
        }else{
            sec.erase(p);
        }
    }
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        sum = 0;

        vector<long long> ans;

        unordered_map<int,int> mp;
        int i=0,j=0;
        while(j<n){
            if(mp[nums[j]]>0){
                rs({mp[nums[j]],nums[j]},x);
            }
            mp[nums[j]]++;
            is({mp[nums[j]],nums[j]},x);

            if(j-i+1==k){
                ans.push_back(sum);

                rs({mp[nums[i]],nums[i]},x);
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }else {
                    is({mp[nums[i]],nums[i]},x);
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};