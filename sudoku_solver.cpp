/*
	Write a program to solve a Sudoku puzzle by filling the empty cells.

	A sudoku solution must satisfy all of the following rules:
		Each of the digits 1-9 must occur exactly once in each row.
		Each of the digits 1-9 must occur exactly once in each column.
		Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
		Empty cells are indicated by the character '.'.
*/

class Solution {
public:
    
    bool ifUnassigned(vector<vector<char>> board, int *row, int *col ) {
        for( int i=0; i<board.size(); i++ ) {
            for( int j=0; j<board.size(); j++ ) {
                if ( board[i][j] == '.' ) {
                    *row = i;
                    *col = j;
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool isSafeCol(vector<vector<char>> board, int col, char ch) {
        for ( int i=0; i<board.size(); i++) {
            if ( board[i][col] == ch )
                return false;
        }
        return true;
    }
    
    bool isSafeRow(vector<vector<char>> board, int row, char ch) {
        for ( int i=0; i<board.size(); i++) {
            if ( board[row][i] == ch )
                return false;
        }
        return true;
    }
    
    bool isSafeBox(vector<vector<char>> board, int startRow, int startCol, char ch ) {
        
        for ( int i=0; i<3; i++) {
            for ( int j=0; j<3; j++) {
                if ( board[i+startRow][j+startCol] == ch )
                    return false;
            }
        }
        return true;
    }
    
    bool isSafe(vector<vector<char>> &board, int row, int col, char ch) {
        return  board[row][col] == '.' && 
                isSafeCol(board, col, ch) &&
                isSafeRow(board, row, ch) &&
                isSafeBox(board, row - (row % 3), col - (col % 3), ch );
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int row, col;
    
        if ( !ifUnassigned(board, &row, &col) )
            return true;
        
        for( char ch = '1'; ch <= '9'; ch++ ) {
           
            if ( isSafe(board,row, col, ch) ) {
                
                board[row][col] = ch;
                
                if ( isValidSudoku(board) )
                    return true;
                
                board[row][col] = '.';
            }
        }
        return false;
    }
	
    void solveSudoku(vector<vector<char>>& board) {
        isValidSudoku(board);
    }
};
