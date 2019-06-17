/*
	Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
	Return the quotient after dividing dividend by divisor.
	The integer division should truncate toward zero.

	Example 1:
		Input: dividend = 10, divisor = 3
		Output: 3
	
	Example 2:
		Input: dividend = 7, divisor = -3
		Output: -2
*/

class Solution {
public:
    int divide(int A, int B) {
     
        bool sign = false;
    
        if ( A == INT_MIN && B == 1 )
            return INT_MIN;


        if ( ( A == INT_MIN && B == -1) || (A == INT_MAX && B == 1) || B == 0 )
            return INT_MAX;

        if ( (A < 0 && B > 0) || (A > 0 && B < 0)) 
            sign = true;
    
        long divisor  = labs(B);
        long dividend = labs(A);
        long ans = 0;

        while ( dividend >= divisor ) {

            long temp = divisor, m = 1;
            while ( (temp << 1) <= dividend ) {
                temp <<= 1;
                m <<= 1;
            }

            dividend = dividend - temp;
            ans = ans + m;
        }
    
        if ( sign )
            return int((-1) * ans);
        return int(ans);
    }
};
