/*
	Write a function to find the longest common prefix string amongst an array of strings.

	If there is no common prefix, return an empty string "".

	Example 1:

	Input: ["flower","flow","flight"]
	Output: "fl"
	Example 2:

	Input: ["dog","racecar","car"]
	Output: ""
	Explanation: There is no common prefix among the input strings.
	Note:

	All given inputs are in lowercase letters a-z.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int i=0, m=0;
        int j=1;
        
        if (strs.size() == 0)
            return "";
            
        if (strs.size() == 1)
            return strs[0];
        
        string prefix = "";
        
        while( m < strs[i].size() && m < strs[j].size() ) {
                
                if (strs[i][m] != strs[j][m])
                    break;
                
                else if ( j+1 == strs.size()) {
                    prefix += strs[i][m];
                    m++;
                    j=1;
                }
            
                else
                    j++;
        }
        
        return prefix;
	}
};
