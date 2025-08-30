class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;

        // Check rows
        for(int i=0;i<n;i++){
            unordered_map<char,int> mp;
            for(int j=0;j<n;j++){
                if(board[i][j] != '.'){
                    if(mp[board[i][j]]) return false;
                    mp[board[i][j]]++;
                }
            }
        }

        // Check columns
        for(int i=0;i<n;i++){
            unordered_map<char,int> mp;
            for(int j=0;j<n;j++){
                if(board[j][i] != '.'){
                    if(mp[board[j][i]]) return false;
                    mp[board[j][i]]++;
                }
            }
        }

        // Check 3x3 subgrids
        for(int i=0;i<n;i+=3){
            for(int j=0;j<n;j+=3){
                unordered_map<char,int> mp;
                for(int r=0;r<3;r++){
                    for(int c=0;c<3;c++){
                        if(board[i+r][j+c] != '.'){
                            if(mp[board[i+r][j+c]]) return false;
                            mp[board[i+r][j+c]]++;
                        }
                    }
                }
            }
        }

        return true;
    }
};
