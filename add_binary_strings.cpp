/*
	Given two binary strings, return their sum (also a binary string).
	The input strings are both non-empty and contains only characters 1 or 0.

	Example 1:
		Input: a = "11", b = "1"
		Output: "100"
	
	Example 2:
		Input: a = "1010", b = "1011"
		Output: "10101"
*/

class Solution {
public:
    string addBinary(string a, string b) {
        
        if ( a.length() < b.length())
            swap(a,b);
        
        int i = a.length()-1;
        int j = b.length()-1;
        
        bool carry = false;
        
        while ( i >= 0 && j >= 0) {
            
            if ( (a[i] == '0' && b[j] == '0' && !carry)  ||
                 ( carry && ((a[i] == '0' && b[j] == '1') ||   
                    (a[i] == '1' && b[j] == '0')) ) )
                a[i] = '0';
            
            else if ( a[i] == '0' && b[j] == '0' && carry ){
                a[i] = '1';
                carry = false;
            }
            
            else if ( (a[i] == '1' && b[j] == '1' && carry) || 
                      (!carry && ((a[i] == '0' && b[j] == '1') ||
                      (a[i] == '1' && b[j] == '0'))) )
                a[i] = '1';
            
            else if ( a[i] == '1' && b[j] == '1' && !carry ) {
                a[i] = '0';
                carry = true;
            }
            i--;
            j--;  
        }
        while ( carry && i >= 0) {
            if ( a[i] == '0') {
                a[i] = '1';
                carry = false;
            }
            else
                a[i] = '0';
            i--;
        }
        
        if ( carry )
            a = "1" + a;
        
        return a;
        
    }
};
