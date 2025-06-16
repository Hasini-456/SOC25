class Solution {
public:
    bool is_valid(vector<vector<char>>& board, int row, int col, char c){
        //row and column
        for(int i=0; i<9; i++){
            if(board[row][i] == c) return false;
            if(board[i][col] == c) return false;
        }

        //checking 3x3 square box
        int rr = 3*(row/3);
        int cc = 3*(col/3);
        for(int r0 = rr; r0< rr+3; r0++){
            for(int c0 = cc; c0< cc+3; c0++){
                if(board[r0][c0] == c) return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board, int row, int col){
        if(row == 9) return true; //all rows(int each row all columns) completed

        if(col == 9) { // a row completed, should go to next row
            return solve(board, row+1, 0);
        }

        if(board[row][col] != '.'){ //we need to solve only fo rthe empty cells
            return solve(board, row, col+1);
        }

        //now solving for the empty cell
        for(char c='1'; c<='9'; c++){
            if(is_valid(board, row, col, c)){
                board[row][col] = c;

                //the following 3 lines are the key for thi sprblm
                //just this is differet from NQueens, remianing same logic
                if(solve(board, row, col+1)){
                    return true; // if we already got a configuration, if we reach to row 9, col 9, then it returns true here, so we are returning here, no need to continue anything, else we go to next line of this if loop
                }

                //backtrack step (undo step)
                board[row][col] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        //solving for an empty cell
        solve(board, 0, 0);
    }
}; 