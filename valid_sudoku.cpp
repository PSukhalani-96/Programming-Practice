/*
	Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

	Each row must contain the digits 1-9 without repetition.
	Each column must contain the digits 1-9 without repetition.
	Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.
*/

class Solution {
public:
    
    bool isSafeCol(vector<vector<char>> board, int col, char ch) {
        int count = 0;
        for ( int i=0; i<board.size(); i++) {
            if ( board[i][col] == ch )
                count++;
        }
        if ( count > 1 )
            return false;
        return true;
    }
    
    bool isSafeRow(vector<vector<char>> board, int row, char ch) {
        int count = 0;
        for ( int i=0; i<board.size(); i++) {
            if ( board[row][i] == ch )
                count++;
        }
        if ( count > 1 )
            return false;
        return true;
    }
    
    bool isSafeBox(vector<vector<char>> board, int startRow, int startCol, char ch ) {
        int count = 0;
        for ( int i=0; i<3; i++) {
            for ( int j=0; j<3; j++) {
                if ( board[i+startRow][j+startCol] == ch )
                    count++;
            }
        }
        if ( count > 1 )
            return false;
        return true;
    }
    
    bool isSafe(vector<vector<char>> &board, int row, int col, char ch) {
        return  isSafeCol(board, col, ch) &&
                isSafeRow(board, row, ch) &&
                isSafeBox(board, row - (row % 3), col - (col % 3), ch );
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for ( int i=0; i<9; i++ ) {
            for ( int j=0; j<9; j++) {
                if ( board[i][j] != '.' && !isSafe(board, i, j, board[i][j]) )
                    return false;
            }
        } 
        
        return true;
    }
};
