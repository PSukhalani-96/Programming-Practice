/*
	Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). 
	n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
	Find two lines, which together with x-axis forms a container, such that the container contains the most water.

	Example:	
		Input: [1,8,6,2,5,4,8,3,7]
		Output: 49
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        if ( height.size() <= 1 )
            return 0;
        
        int maxArea = 0;
        int lower = 0, upper = height.size()-1;
        
        while ( lower < upper ) {
            int val = min(height[lower], height[upper]);
            maxArea = max(maxArea, val * (upper - lower));
            if ( height[lower] < height[upper] )
                lower++;
            else
                upper--;
        }
		return maxArea;
    }
};
