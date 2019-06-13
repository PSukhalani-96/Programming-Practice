/*
	Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

	Example:
		Input: S = "ADOBECODEBANC", T = "ABC"
		Output: "BANC"
*/

class Solution {
public:
    string minWindow(string s, string t) {
     
        if ( s.length() < t.length() )
            return "";
        
        int hash_st[256]  = {0};
        int hash_pat[256] = {0};
  
        for (int i=0; i<t.length(); i++)
            hash_pat[t[i]]++;
        
        int count = 0;
        int start = 0;
        int start_index = -1;
        int min_len = INT_MAX;
        
        for ( int i = 0; i<s.length(); i++ ) {
            
            hash_st[s[i]]++;
            
            if ( hash_pat[s[i]] != 0 && hash_st[s[i]] <= hash_pat[s[i]])
                count++;
            
            if ( count == t.length()) {
                
                while ( hash_pat[s[start]] == 0 || ( hash_st[s[start]] > hash_pat[s[start]] )) {
                    if ( hash_st[s[start]] > hash_pat[s[start]] )
                        hash_st[s[start]]--;
                    start++;
                }
                
                int len = i - start + 1;
                if ( min_len > len ) {
                    min_len = len;
                    start_index = start;
                }
            }
        }

        if ( start_index == -1 )
            return "";
        return s.substr(start_index, min_len);
        
    }
};
