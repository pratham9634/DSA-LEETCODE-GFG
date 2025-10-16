class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int> mp;
        for (int x : nums) {
            int mod = ((x % value) + value) % value; 
            mp[mod]++;
        }
        int i=0;
        while(i<1000000000){
            if(mp.find(i%value)==mp.end()) break;
            mp[i%value]--;
            if(mp[i%value]==0)mp.erase(i%value);
            i++;
        }
        return i;
    }
};