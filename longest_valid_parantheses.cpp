/*
	Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses 
	substring.

	Example 1:
		Input: "(()"
		Output: 2
		Explanation: The longest valid parentheses substring is "()"
	
	Example 2:
		Input: ")()())"
		Output: 4
		Explanation: The longest valid parentheses substring is "()()"
*/

// Also go through DP and stack approach

class Solution {
public:
    int longestValidParentheses(string s) {
        
        
        int left  = 0;
        int right = 0;
        int max_paran = 0;
        
        for ( int i=0; i<s.length(); i++) {
            if ( s[i] == '(' )
                left++;
            else
                right++;
            
            if ( left == right )
                max_paran = max(max_paran, 2*right);
            
            else if ( right >= left )
                right = left = 0;
        }
        
        left = right = 0;
        for ( int i=s.length()-1; i>=0; i--) {
            if ( s[i] == '(' )
                left++;
            else
                right++;
            
            if ( left == right )
                max_paran = max(max_paran, 2*left);
            
            else if ( left >= right )
                right = left = 0;
        }
        
        return max_paran;
        
    }
};
