/*
Using Dynamic Programming Approach

	Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

	Example 1:
		Input: "babad"
		Output: "bab"
		Note: "aba" is also a valid answer.
	
	Example 2:
		Input: "cbbd"
		Output: "bb"
*/

class Solution {
public:
    string longestPalindrome(string s) {
        
        if ( s.size() == 0)
            return "";
        
        int N = s.length();
        bool L[N][N];
        int max = 0;
        int start = 0;
        int end = 0;
        
        
        for ( int i=0; i<N-1; i++) {
            L[i][i] = 1;
            if ( s[i] == s[i+1] ) {
                L[i][i+1] = true; 
                start = i;
                end = i+1;
            }
            else
                L[i][i+1] = false;
        }
        
        for ( int k=2; k<N; k++) {
            for ( int i=0; i<N-k; i++) {
                int j = k + i;
                if ( s[i] == s[j] && L[i+1][j-1] && k+1 >= max) {
                    L[i][j] = true;
                    max = k+1;
                    start = i;
                    end = j;
                }
                else
                    L[i][j] = false;
            }
        }
      
        string res = "";
        res = s.substr(start,end+1);
        res[end-start+1] = '\0';
        return res;
        
    }
};
