/*
	The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
	Given an integer n, return the number of distinct solutions to the n-queens puzzle.

	Example:
		
		Input: 4
		Output: 2
		Explanation: There are two distinct solutions to the 4-queens puzzle as shown below.
			[
	 			[".Q..",  // Solution 1
	  			 "...Q",
	  			 "Q...",
	  			 "..Q."],

				 ["..Q.",  // Solution 2
				  "Q...",
				  "...Q",
				  ".Q.."]
			]
*/

class Solution {
public:
    
    bool isSafe(vector<string> &board, int col, int row) {

        int N = board.size();

        for (int i=0; i<col; i++) {
            if ( board[row][i] == 'Q' )
                return false;
        }

        for(int i = row, j = col; i >= 0 && j >= 0; i--, j-- ) {
            if ( board[i][j] == 'Q')
                return false;
        }

        for(int i = row, j = col; i < N && j >= 0; i++, j-- ) {
            if ( board[i][j] == 'Q')
                return false;
        }
        return true;
    }
	
	void N_Queen( vector<string> &board, int &count, int col ) {

        int N = board.size();

        if ( col == N ) {

            count++;
            return ;
        }

        for ( int i=0; i<N; i++ ) {

            if ( isSafe(board, col, i) ) {
                board[i][col] = 'Q';
                N_Queen(board, count, col+1);
                board[i][col] = '.';
            }
        }
    }
	
    int totalNQueens(int n) {
        
        int count = 0;
        vector<string> board(n, std::string(n, '.'));
        N_Queen(board, count, 0); 
        return count;
    }
};
