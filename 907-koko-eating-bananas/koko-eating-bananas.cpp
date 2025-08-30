class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int i=1;
        int j = *max_element(piles.begin(),piles.end());

        while(i<j){
            int mid = i + (j-i)/2;
            int k = 0;

            for(int c=0;c<piles.size();c++){
                k+=(piles[c]-1)/mid+1;
            }
            if(k<=h) j=mid;
            else i = mid+1;
        }
        return i;
    }
};