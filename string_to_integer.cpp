/*
	Implement atoi to convert a string to an integer.

	Example :
		Input : "9 2704"
		Output : 9
*/

typedef long double ll;

int Solution::atoi(const string A) {
    
    int i=0;
    while ( i<A.length() && A[i] == ' ')
        i++;
        
    ll num = 0;
    bool negate = false;
    
    if ( A[i] == '-' ) {
        i++;
        negate = true;
    }
        
    if ( A[i] == '+' ) 
        i++;
        
    if ( !isdigit(A[i]) )
        return 0;
        
    while ( i < A.length() && isdigit(A[i]) ) {
        num = num*10 + (A[i] - '0');
        i++;
    }
    
    if ( negate )
        num = -num;
        
    if ( num > INT_MAX )
        return INT_MAX;
    
    else if ( num < INT_MIN )
        return INT_MIN;
        
    return (int)num;
}
