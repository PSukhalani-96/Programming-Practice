/*
	Given n non-negative integers representing an elevation map where the width of each bar is 1, 
	compute how much water it is able to trap after raining.

	Example:

	Input: [0,1,0,2,1,0,1,3,2,1,2,1]
	Output: 6
	
	Space Complexity: O(1)
	Time  Complexity: O(N)
*/

class Solution {
public:
    int trap(vector<int>& height) {
     
        int low = 0;
        int high = height.size()-1;
        int maxl = 0, maxr = 0;
        int amount = 0;
        
        while ( low <= high ){
            
            if ( height[low] < height[high] ) {
                    
                if ( height[low] > maxl )
                    maxl = height[low];
                else {
                    amount += maxl - height[low];
                    low++;
                }
            }
            
            else {
                if ( height[high] > maxr )
                    maxr = height[high];
                else {
                    amount += maxr - height[high];
                    high--;
                }
            }
        }
        
        return amount;
    }
};
