class Solution {
public:
     long long minimumRemoval(vector<int>& v) 
    {
        int n = v.size();
        sort(v.begin(), v.end());
		long long rightSum = accumulate(v.begin(), v.end(), 0LL), leftSum = 0, res = 1e13;
        
        for(int i = 0; i < n; i++)
        {
		 long long temp = leftSum + rightSum - (n-i)*(long long)v[i];
            res = min(res, temp);
            leftSum += v[i];
            rightSum -= v[i];
        }
        return res;
    }
};