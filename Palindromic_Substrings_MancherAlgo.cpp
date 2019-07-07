/*
	Given a string, your task is to count how many palindromic substrings in this string.

	The substrings with different start indexes or end indexes are counted as different substrings even they consist of same 
	characters.

	Example 1:
		Input: "abc"
		Output: 3
		Explanation: Three palindromic strings: "a", "b", "c".
 
 	Example 2:
		Input: "aaa"
		Output: 6
		Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
*/

class Solution {
public:
    int countSubstrings(string s) {
        
        int left = 0;
        int C = 1;
        int right = 2;
        int currentLeft = -1, currentRight = -1;
        int diff;
        
        int N = s.length();
        N = 2*N + 1;
        int L[N];
        L[0] = 0;
        L[1] = 1;
        bool expand = false;
        
        for ( int i=2; i<N; i++ ){
            
            currentLeft = 2*C - i;
            diff = right - i;
            
            expand = false;
            
            if ( diff > 0 ) {
                
                if ( L[currentLeft] < diff )
                    L[i] = L[currentLeft];
                
                else if ( L[currentLeft] == diff && i == N-1 )
                    L[i] = L[currentLeft];
                
                else if ( L[currentLeft] == diff && i < N-1 ) {
                    L[i] = L[currentLeft];
                    expand = true;
                }
                
                else if ( L[currentLeft] > diff  ){
                    L[i] = diff;
                    expand = true;
                }
            }
            
            else {
                L[i] = 0;
                expand = true;
            }
            
            if ( expand ) {
                
                while ( ( i+L[i] < N && i-L[i] > 0 && ( ((i+L[i]+1) % 2 == 0) ||
                            s[(i+L[i]+1)/2] == s[(i-L[i]-1)/2])) )
                    L[i]++;
            }

            if ( i + L[i] > right ){
                C = i;
                right = i + L[i];
            }
        }
        
        int count = 0;
        
        for(int i=0; i<N; i++) 
            count += (L[i]+1)/2;
        
        return count;
    }
};
