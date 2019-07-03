/*
	Given two words A and B, find the minimum number of steps required to convert A to B. 
	(each operation is counted as 1 step.)

	You have the following 3 operations permitted on a word:

	Insert a character
	Delete a character
	Replace a character
	
	Example : 
		edit distance between
			"Anshuman" and "Antihuman" is 2.

		Operation 1: Replace s with t.
		Operation 2: Insert i.
*/
int Solution::minDistance(string A, string B) {
    
    A = " " + A;
    B = " " + B;
    
    int m = A.length();
    int n = B.length();
    
    int T[m][n];
    
    for ( int i=0; i<n; i++ )
        T[0][i] = i;
        
    for ( int i=0; i<m; i++ )
        T[i][0] = i;
        
    for ( int i=1; i<m; i++ ) {
        for ( int j=1; j<n; j++ ) {
            if ( A[i] == B[j] )
                T[i][j] = T[i-1][j-1];
            else  
                T[i][j] = min(T[i-1][j-1] , min(T[i-1][j], T[i][j-1])) + 1;
        }
    }
    return T[m-1][n-1];
}
