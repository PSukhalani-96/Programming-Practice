/*
	Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented 
	into a space-separated sequence of one or more dictionary words.

	Note:
		The same word in the dictionary may be reused multiple times in the segmentation.
		You may assume the dictionary does not contain duplicate words.
	
	Example 1:
		Input: 	s = "leetcode", wordDict = ["leet", "code"]
		Output: true
		Explanation: Return true because "leetcode" can be segmented as "leet code".
	
	Example 2:
		Input: 	s = "applepenapple", wordDict = ["apple", "pen"]
		Output: true
		Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
				 	  
	Note that you are allowed to reuse a dictionary word.
	
	Example 3:

		Input: 	s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
		Output: false
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int N = s.length();
        int M = wordDict.size();
        vector<int> matched_index;
        
        matched_index.push_back(-1);
        bool dp[N] = {false};
        
        for ( int i=0; i<N; i++) {
            
            int size = matched_index.size();
            bool flag = false;
            
            for ( int j=size-1; j>=0; j--) {
                string res = s.substr(matched_index[j]+1, i-matched_index[j]);
                
                for ( int k=0; k<M; k++) {
                    if ( res == wordDict[k] ){
                        flag = true;
                        break;
                    }
                }
                
                if ( flag ){
                    matched_index.push_back(i);
                    dp[i] = true;
                    break;
                }
            }
            
            if ( !flag )
                dp[i] = false;
        }
        
        return dp[N-1];
    }
};
