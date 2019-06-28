/*
	Given an array arr[] of size N. The task is to find the first repeating element in an array of integers, i.e., 
	an element that occurs more than once and whose index of first occurrence is smallest.

	Input :
		The first line contains an integer T denoting the total number of test cases. 
		In each test cases, First line is number of elements in array N and second its values.

	Output:
		In each separate line print the index of first repeating element, 
			if there is not any repeating element then print “-1” (without quotes). 
		Use 1 Based Indexing.

	Constraints:
		1 <= T <= 500
		1 <= N <= 106
		0 <= Ai <= 106

	Example:
		Input:
			1
			7
			1 5 3 4 3 5 6

		Output:
			2

		Explanation: 
			Testcase 1: 5 is appearing twice and its first appearence is at index 2 which is less than 3 whose first 
						occuring index is 3.
*/

#include <iostream>
#include <unordered_map>
using namespace std;

int first_repeating(int arr[], int N) {
    
    unordered_map<int, int> m;
    
    for ( int i=0; i<N; i++ ) {
        
        if ( m.find(arr[i]) == m.end() )
            m.insert(make_pair(arr[i], 1));
    
        else {
            auto itr = m.find(arr[i]);
            (*itr).second = (*itr).second + 1;
        }
    }
    
    for ( int i=0; i<N; i++ ) {
        if ( m.find(arr[i]) != m.end()  ) {
            auto itr = m.find(arr[i]);
            if ( (*itr).second > 1 )
                return i+1;
        }
    }
    return -1;
}
int main() {

	int t;
	cin >> t;
	while ( t-- ) {
	    int N;
	    cin >> N;
	    int arr[N];
	    for(int i=0; i<N; i++)
	        cin >> arr[i];
	        
	    cout << first_repeating(arr, N) << endl;
	}
	return 0;
}
