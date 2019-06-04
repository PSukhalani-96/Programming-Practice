/*
	Given an unsorted integer array, find the smallest missing positive integer.

	Example 1:
		Input: [1,2,0]
		Output: 3
	
	Example 2:
		Input: [3,4,-1,1]
		Output: 2
	
	Example 3:
		Input: [7,8,9,11,12]
		Output: 1
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        set<int> s;
        
        for ( int x : nums ) {
            if ( x > 0 )    
                s.insert(x);
        }
        
        int i=1;
        
        while ( i>0) {
            set<int>::iterator itr = s.find(i);
            if ( itr == s.end() ) 
                return i;
            i++;    
        }
        return 1;
    }
};
