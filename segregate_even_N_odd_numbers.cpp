/*
	Given an array A[], write a program that segregates even and odd numbers. The program should put all even numbers first 
	in sorted order, and then odd numbers in sorted order.

	Input:	The first line of input contains an integer T, denoting the number of test cases. For each testcase there will be 
			two lines of input: The first line contains a single integer N denoting the size of array.
			The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

	Output:	For each testcase, print the segregated array.

	Constraints:
		1 ≤ T ≤ 100
		1 ≤ N ≤ 105
		0 ≤A[i]<=105

	Example:
		Input:
			2
			7
			12 34 45 9 8 90 3
			5
			0 1 2 3 4

		Output:
			8 12 34 90 3 9 45
			0 2 4 1 3
*/

#include <iostream>
#include <algorithm>
using namespace std;

void segregate_even_N_odd(int arr[], int N) {
    
    int j=0;
    for (int i=0; i<N; i++) {
        if ( arr[i] % 2 == 0) {
            swap(arr[i], arr[j]);
            j++;
        }
    }
    
    sort(arr, arr+j);
    sort(arr+j, arr+N);
}

int main() {
	//code
	
	int t;
	cin >> t;
	while ( t-- ) {
	    int N;
	    cin >> N;
	    int arr[N];
	    for(int i=0; i<N; i++)
	        cin >> arr[i];
	    segregate_even_N_odd(arr, N);
	    for ( int i=0; i<N; i++)
	        cout << arr[i] << " ";
	        
	   cout << endl;
	}
	return 0;
}
