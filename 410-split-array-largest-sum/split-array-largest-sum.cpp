class Solution {
public:
    bool check(vector<int>&arr,int k,int m){
        int c =1;
        int sum = 0;

        for(int i=0;i<arr.size();i++){
            if(sum+arr[i]>m){
                c++;
                sum = arr[i];
            }
            else sum+=arr[i];
        }
        return c<=k;
    }
    int splitArray(vector<int>& arr, int k) {
        int lo = *max_element(arr.begin(), arr.end());
        int hi = accumulate(arr.begin(), arr.end(), 0);
         int res = -1;
    
    while(lo <= hi) {
        int mid = lo + (hi - lo)/2;
        
        if(check(arr, k, mid)){
            res = mid;
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }
    
    return res;
        
    }
};