/*
	Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

	Your algorithm should run in O(n) complexity.

	Example:
		Input: [100, 4, 200, 1, 3, 2]
		Output: 4
		Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
            
        unordered_set<int> s;
        for(int x: nums)
            s.insert(x);
        
        int longest = 0;
        int length = 0;
        for(int x: nums) { 
            
            if ( s.find(x-1) == s.end() && s.find(x) != s.end() ){
                length++;
                int np = x;
                while (s.find(np+1) != s.end()) {
                    length++;
                    np = np+1;
                }
                longest = max(longest, length);
                length = 0;
            }
        }
        
        return longest;
    }
};
