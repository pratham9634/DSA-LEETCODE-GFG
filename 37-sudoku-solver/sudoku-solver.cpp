class Solution {
public:
    bool safe(vector<vector<char>>& b,int r,int c,int num){
        for(int i=0;i<9;i++){
            if(b[r][i]==num || b[i][c]==num) return false;
        }
        int boxRowStart = (r / 3) * 3;
        int boxColStart = (c / 3) * 3;
        for (int i = boxRowStart; i < boxRowStart + 3; i++) {
            for (int j = boxColStart; j < boxColStart + 3; j++) {
                if (b[i][j] == num) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board,int r,int c){
        if(r==9) return true;
        if(c==9) return solve(board,r+1,0);

        if(board[r][c]!='.') return solve(board,r,c+1);

        for(char i ='1';i <= '9';i++){
            if(safe(board,r,c,i)){
                board[r][c]=i;
                if(solve(board,r,c+1)) return true;
                board[r][c]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
    }
};