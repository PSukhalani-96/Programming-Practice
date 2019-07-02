/*
	Given an array A of N positive numbers. The task is to find the position where equilibrium first occurs in the array. 
	Equilibrium position in an array is a position such that the sum of elements before it is equal to the sum of elements 
	after it.

	Input:
		The first line of input contains an integer T, denoting the number of test cases. Then T test cases follow. 
		First line of each test case contains an integer N denoting the size of the array. 
		Then in the next line are N space separated values of the array A.

	Output:
		For each test case in a new  line print the position at which the elements are at equilibrium if no equilibrium point
		exists print -1.

	Constraints:
		1 <= T <= 100
		1 <= N <= 106
		1 <= Ai <= 108

	Example:
		Input:
			2
			1
			1
			5
			1 3 5 2 2

		Output:
			1
			3

	Explanation:
		Testcase 1: Since its the only element hence its the only equilibrium point.
		Testcase 2: For second test case equilibrium point is at position 3 as elements below it (1+3) = elements 
					after it (2+2).
*/

int equilibrium(int arr[], int N) {
    
    int low  = 0;
    int high = N-1;
    int sum_left = 0;
    int sum_right = 0;
    
    while ( low < high ) {
        
        if ( sum_left == sum_right ){
            sum_left += arr[low];
            sum_right += arr[high];
            low++;
            high--;
        }
        else if ( sum_left > sum_right) {
            sum_right += arr[high];
            high--;   
        }
        
        else {
            sum_left += arr[low];                                                                                                                                                                                                           
            low++;
        }
    }
    
    if ( low == high && sum_left == sum_right )
        return low+1;
    return -1;
}
