class Solution {
   public:
    bool isValid(int row, int col, vector<string>& board, int n) {

        //checking up
        for(int i=row-1;i>=0;i--){
            if(board[i][col]=='Q'){
                return false;
            }
        }

        //checking left diagonal
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }

        //checking right diagonal
        for(int i=row-1, j=col+1; i>=0 && j<n; i-- , j++){
            if(board[i][j]=='Q'){
                return false;
            }
        }

        return true;

    }
    void solve(vector<string>& board, vector<vector<string>>& ans, int n,
               int row) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isValid(row, col, board, n) == true) {
                board[row][col] = 'Q';

                solve(board, ans, n, row + 1);

                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;

        vector<string> board(n, string(n, '.'));
        int row = 0;
        solve(board, ans, n, row);
        return ans;
    }
};