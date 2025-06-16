class Solution {
public:
    bool is_safe(int row, int col, vector<string> &board, int n){
        //check column
        for(int i=0; i<row; i++){
            if(board[i][col] == 'Q') return false;
        }
        //left diagonal
        for(int i= row-1, j =col-1; i>=0 && j>=0 ; i--,j--){
            if(board[i][j] == 'Q') return false;
        }
        //right diagonal
        for(int i=row-1, j = col+1; i>=0 && j<n; i--, j++){
            if(board[i][j] == 'Q') return false;
        }

        return true;
    }

    void solve(int row, vector<string> &board, vector<vector<string>> &res, int n){
        if(row == n){
            res.push_back(board);
            return;
        }

        for(int col = 0; col<n; col++){
            if(is_safe(row, col, board, n)){
                board[row][col] = 'Q';
                solve(row+1, board, res, n);
                board[row][col] = '.'; //backtrack  //this is the only key imp line in the entire code 
                // apart from above line, remaining just forward soln, if safe placing queen in that row, gng to next line,
                //else we do not go to further rows
                // if we are unable to reach end of all rows, we dont push it to res
                //just a brute force idea  
            }       
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        solve(0, board, res, n);
        return res;
    }
};