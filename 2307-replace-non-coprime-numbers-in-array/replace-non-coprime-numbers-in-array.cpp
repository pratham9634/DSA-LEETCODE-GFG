class Solution {
public:
    int Lcm(int a, int b) {
        return (a / gcd(a, b)) * b;
    }
    
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st;
        
        for (int x : nums) {
            st.push_back(x);
            
            while (st.size() >= 2) {
                int y = st.back();       
                int z = st[st.size() - 2]; 
                
                if (gcd(y, z) > 1) {
                    st.pop_back();
                    st.pop_back();
                    int merged = Lcm(y, z);
                    st.push_back(merged);
                } else {
                    break; 
                }
            }
        }
        
        return st;
    }
};