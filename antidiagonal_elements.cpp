/*
	Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details.
	
	Example:
		Input: 	

			1 2 3
			4 5 6
			7 8 9

		Return the following :

			[ 
  				[1],
  				[2, 4],
  				[3, 5, 7],
  				[6, 8],
  				[9]
			]
*/

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    
    int N = A.size();
    int count = 0;
    int row = (2*N) - 1;
    int i = 0,  j = 0;
    int prev_i = 0, prev_j = 0;
    vector<vector<int>> res(row);
    
    while ( count < row ) {
        while ( i < N && j >= 0 ) {
            
            res[count].push_back(A[i][j]);
            i++;
            j--;
        }
        count++;
        if ( prev_j == N-1)
            j = prev_j;
        else {
            prev_j++;
            j = prev_j;
        }
        
        if (  i == N )  {
            prev_i++;
            i = prev_i;
        }
        else
            i = 0;
    }
    return res;
}
