class Solution {
public:
    int totalFruit(vector<int>& f) {
        int n = f.size();
        int j =0,ans = -1;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[f[i]]++;
            while(mp.size()>2){
                mp[f[j]]--;
                if(mp[f[j]]==0)mp.erase(f[j]);
                j++;
            }
            ans = max(ans,i-j+1);
        }
        return ans;
    }
};