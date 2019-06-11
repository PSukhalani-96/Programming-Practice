/*
	Given a non-negative number represented as an array of digits,
	Add 1 to the number ( increment the number represented by the digits ).
	The digits are stored such that the most significant digit is at the head of the list.

	Example:
		If the vector has [1, 2, 3]
		the returned vector should be [1, 2, 4]
		as 123 + 1 = 124.
*/

vector<int> Solution::plusOne(vector<int> &A) {
    
    int i = 0;
    while ( A[i] == 0 ) {
        if ( A.size() == 1)
            break;
        A.erase(A.begin());
    } 
    
    int N = A.size();
    
    if ( N == 0)
        return {};
    
    int res = A[N-1] + 1;
    A[N-1] = res  % 10;
    int carry = res / 10;
    
    if ( carry == 1) {
        i = N-2;
        while(carry && i >= 0) {
            res   = A[i] + carry;
            A[i]  = res % 10;
            carry = res / 10;
            i--;
        }
        
        if ( i == -1 && carry == 1)
            A.insert(A.begin(), carry);
    }
    return A;
}
