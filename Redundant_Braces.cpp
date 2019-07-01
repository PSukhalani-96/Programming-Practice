/*
	Write a program to validate if the input string has redundant braces?
	Return 0/1

	0 -> NO
	1 -> YES
	Input will be always a valid expression

	and operators allowed are only + , * , - , /

	Example:

	((a + b)) has redundant braces so answer will be 1
	(a + (a + b)) doesn't have have any redundant braces so answer will be 0
*/

int Solution::braces(string A) {
    
    if ( A.length() == 0)
        return 1;
        
    stack<char> s;
    s.push(A[0]);
    
    for ( int i=0; i<A.length(); i++){
        if ( A[i] == '(' || A[i] == '+' || A[i] == '-' || A[i] == '*' || A[i] == '/' )
            s.push(A[i]);
            
        else if ( A[i] == ')' ) {
            if ( s.top() == '(')
                return 1;
            while ( !s.empty() && s.top() != '(')
                s.pop();
            s.pop();
        }
    }
    return 0;
}
