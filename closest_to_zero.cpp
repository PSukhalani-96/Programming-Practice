/*
	Given an integer array A of N elements. You need to find the sum of two elements such that sum is closest to zero.

	Input:
		The first line of input contains an integer T denoting the number of test cases.  
		The first line of each test case is N, denoting the size of array. 
		Each test case consist of a N integers which are the array elements.

	Output:
		Print the requiired sum which is closest to zero.

	Constraints:
		1 ≤ T ≤ 100
		1 ≤ N ≤ 103
		-106 ≤ a[i] ≤ 106

	Example:
		Input:
			3
			3
			-8 -66 -60  
			6
			-21 -67 -37 -18 4 -65  
			2
			-24 -73

		Output:
			-68
			-14
			-97

	Explanation:
		Testcase 1: Sum of two elements closest to zero is -68 using numbers -60 and -8.
*/

int closest_zero(vector<int> arr) {
    
    sort(arr.begin(), arr.end());
    
    int low  = 0;
    int high = arr.size()-1;
    int positive = INT_MAX;
    int negative = INT_MIN;
    int poslowest = 0;
    int neglowest = 0;

    while ( low < high ) {
        int temp = arr[low] + arr[high];
        
        if ( temp > 0 ) {
            if ( temp < positive ) {
                positive = temp;
                poslowest = low;
            }
            high--;
        }
        
        else {
            if ( temp > negative ) {
                negative = temp;
                neglowest = low;
            }
            low++;
        }
    }

    if ( abs(negative) == positive ) {
        if ( neglowest < poslowest)
            return negative;
        else 
            return positive;
    }
    return abs(negative) > positive ? positive : negative;
}
