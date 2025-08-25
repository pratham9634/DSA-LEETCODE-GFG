class Solution {
public:
    string decodeCiphertext(string encoded, int rows) {
        
        int n = encoded.size();
        int cols = n / rows;
        vector<vector<char>> arr(rows, vector<char>(cols));
        int k = 0;
        
		// filling the vector
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                arr[i][j] = encoded[k++];
            }
        }
        
        string original = "";
        
		// diagonal traversal as shown in image 
        for(int col = 0; col < cols; col++) {
            int r = 0;
            int c = col;
            while(c < cols and r < rows) {
                original += arr[r++][c++];
            }
        }
        
		// removing trailing zeros
        while(!original.empty() && original.back() == ' ') original.pop_back();
        
        return original;
    }
};