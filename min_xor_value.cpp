/*
	Given an array of N integers, find the pair of integers in the array which have minimum XOR value. Report the minimum XOR 
	value.

	Examples : 
		Input 
			0 2 5 7 
		Output 
			2 (0 XOR 2) 
	
		Input 
			0 4 7 9 
		Output 
			3 (4 XOR 7)

	Constraints: 
		2 <= N <= 100000 
		0 <= A[i] <= 1000000000
*/

int Solution::findMinXor(vector<int> &A) {
    
    sort(A.begin(), A.end());
    int min = INT_MAX;
    for ( int i=0; i<A.size()-1; i++) {
        if ( (A[i] ^ A[i+1]) < min )
            min = A[i] ^ A[i+1];
    }
    return min;
}
