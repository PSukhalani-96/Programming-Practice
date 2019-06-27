/*
	Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
	find the area of largest rectangle in the histogram.

	Let say there is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
	The largest rectangle is shown in the shaded area, which has area = 10 unit.

 	Example:
		Input: [2,1,5,6,2,3]
		Output: 10
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        if ( heights.size() == 0)
            return 0;
        
        if ( heights.size() == 1)
            return heights[0];
        
        stack<pair<int, int>> s;
        s.push(make_pair(heights[0], 0));
        int left = -1;
        
        int area = -1;
        
        for ( int i=1; i<=heights.size(); i++ ) {
            
            while ( !s.empty() && ( i == heights.size() || heights[i] < s.top().first )) {
                
                if ( s.size() == 1 )
                    left = -1;
                else {
                    pair<int, int> temp = s.top();
                    s.pop();
                    left = s.top().second;
                    s.push(temp);
                }
                
                int currentArea = s.top().first * ( i - left - 1);
                s.pop();
                area = max(currentArea, area);
                
            }
            
            if ( i < heights.size() ) 
                s.push(make_pair(heights[i],i));
            
        }
        return area;
    }
};
