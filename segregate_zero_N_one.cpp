/*
	Given a binary array A[] of size N. The task is to arrange array in increasing order.
	Note: The binary array contains only 0  and 1.

	Input:	The first line of input contains an integer T, denoting the testcases. Every test case contains two lines, 
			first line is N(size of array) and second line is space separated elements of array.

	Output: Space separated elements of sorted arrays. There should be a new line between output of every test case.

	Constraints:
		1 < = T <= 100
		1 <= N <= 106
		0 <= A[i] <= 1

	Example:
		Input:
			2
			5
			1 0 1 1 0
			10
			1 0 1 1 1 1 1 0 0 0

		Output:
		0 0 1 1 1
		0 0 0 0 1 1 1 1 1 1
*/

#include <iostream>
using namespace std;

void segregate_zero_N_one(int arr[], int N) {
    
    int j=0;
    for(int i=0; i<N; i++) {
        if ( arr[i] == 0 ) {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

int main() {
	int t;
	cin >> t;
	
	while ( t-- ) {
	    int N;
	    cin >> N;
	    int arr[N];
	    for ( int i=0; i<N; i++)
	        cin >> arr[i];
	        
	    segregate_zero_N_one(arr, N);
	    
	    for ( int i=0; i<N; i++)
	        cout << arr[i] << " ";
	    cout << "\n";
	}
	return 0;
}
