/*
	Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

	A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

	Example:
		Input: "23"
		Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/

class Solution {
public:
    
    void solve ( string A, int i, vector<string> &ans, string res ) {
    
        if ( i >= A.length()) {
            res[res.length()] = '\0';
            ans.push_back(res);
            return;
        }
        string digits[10] = { "0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

        char ch = A[i];
        int  index = ch - '0';
        int  N  = digits[ch - '0'].length();

        for ( int j=0; j<N; j++ ) {
            solve(A, i+1, ans, res + digits[index][j]);
        }
    }
    vector<string> letterCombinations(string A) {
        if ( A.length() == 0)
        return {};
        
        vector<string> ans;

        solve ( A, 0, ans, "");

        return ans;
    }
};
