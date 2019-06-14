/*
Given an input string, reverse the string word by word.

Example 1:
	Input: "the sky is blue"
	Output: "blue is sky the"

Example 2:
	Input: "  hello world!  "
	Output: "world! hello"
	Explanation: Your reversed string should not contain leading or trailing spaces.

Example 3:
	Input: "a good   example"
	Output: "example good a"
	Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
*/

class Solution {
public:
    
    void reverseString(string &s, int lower,int upper) {
        
        while ( lower < upper ) {
            swap(s[lower], s[upper]);
            lower++;
            upper--;
        }
       
    }
    
    string reverseWords(string s) {
        
        int i=0;
        while ( i<s.length() && s[i]==' ')
            i++;
        
        s.erase(s.begin(), s.begin()+i);
        
        i = s.length()-1;
        while ( i>=0 && s[i]==' ')
            i--;
        
        s.erase(s.begin()+i+1, s.end());
        
        int j=0;
        i = 0;
        bool flag = false;
        while ( i < s.length() ){
        
            if ( s[i] != ' ') {
                if (flag) {
                    s[j] = ' ';
                    j++;
                    flag = false;
                }
                s[j] = s[i];
                j++;
                i++;
            }
            else {
                i++;
                flag = true;
            }
        }
        s.erase(s.begin()+j, s.end());
        
        j = 0;
        for( i=0; i<s.length(); i++) {
            if ( s[i] == ' ') {
                cout << i << " " << j << " ";
                reverseString(s, j, i-1);
                j = i+1;
            }
        }
        
        reverseString(s,j,i-1);
        
        reverse(s.begin(), s.end());
        
        return s;
    }
};
