/*
	You are given a read only array of n integers from 1 to n.
	Each integer appears exactly once except A which appears twice and B which is missing.
	Return A and B.

	Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
	Note that in your output A should precede B.

	Example:
		Input:[3 1 2 5 3] 
		Output:[3, 4] 
		A = 3, B = 4
*/

vector<int> Solution::repeatedNumber(const vector<int> &A) {

    int xor1 = 0;
    int n = A.size();
    for ( int i=0; i<n; i++)
        xor1 = xor1 ^ A[i];
        
    for ( int i=1; i<=n; i++)
        xor1 = xor1 ^ i;
        
    int set_bit = xor1 & ~(xor1 - 1);
    
    int missing = 0;
    int repeated = 0;
    
    for ( int i=0; i<n; i++) {
        if ( set_bit & A[i] )
            missing = missing ^ A[i];
        else
            repeated = repeated ^ A[i];
    }
    
    for ( int i=1; i<=n; i++) {
        if ( set_bit & i )
            missing = missing ^ i;
        else
            repeated = repeated ^ i;
    }
    
    bool flag = false;
    for ( int i=0; i<n; i++) {
        if ( A[i] == missing ) {
            flag = true;
            break;
        }
    }
    
    vector<int> res;
    if ( flag )
        swap(missing, repeated);
        
    res.push_back(repeated);
    res.push_back(missing);
    
    return res;
    
}
