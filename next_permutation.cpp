/*
	Implement the next permutation, which rearranges numbers into the numerically next greater permutation of numbers.
	If such arrangement is not possible, it must be rearranged as the lowest possible order ie, sorted in an ascending order.
	The replacement must be in-place, do not allocate extra memory.

	Examples:
		1,2,3 		→ 1,3,2
		3,2,1 		→ 1,2,3
		1,1,5 		→ 1,5,1
		20, 50, 113 → 20, 113, 50
*/

void Solution::nextPermutation(vector<int> &A) {
 
    int i = A.size()-1;
    for ( i=A.size()-2; i>=0; i--) {
        if ( A[i] < A[i+1])
            break;
    }
    
    int j = i+1;
    while ( j<A.size() && A[i] < A[j])
        j++;
        
    if( i >= 0 && j-1 < A.size() )    
        swap(A[i], A[j-1]);
    
    int lower = i+1;
    
    reverse(A.begin()+lower, A.end());
}
