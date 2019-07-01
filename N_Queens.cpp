/*
	The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
	Given an integer n, return all distinct solutions to the n-queens puzzle.

	Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen 
	and an empty space respectively.

	Example:

		Input: 4
		Output: [
		 			[".Q..",  // Solution 1
		 			 "...Q",
		 			 "Q...",
		 			 "..Q."],

		 			["..Q.",  // Solution 2
		 			 "Q...",
		 			 "...Q",
		 			 ".Q.."]
					]
		Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.
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

    
    void N_Queen(vector<vector<string>> &res, vector<string> &board, int col ) {
    
        int N = board.size();
        
        if ( col == N ) {
            
            res.push_back(board);
            return ;
        }

        for ( int i=0; i<N; i++ ) {
            
            if ( isSafe(board, col, i) ) {
                board[i][col] = 'Q';
                N_Queen(res, board, col+1);
                board[i][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int A) {
        
        vector<string> board(A, std::string(A, '.'));
        vector<vector<string>> res;
        N_Queen(res, board, 0); 
        return res;
    }
};
