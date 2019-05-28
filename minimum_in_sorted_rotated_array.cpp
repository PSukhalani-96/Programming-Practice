/*
	Approach: Modified Binary Search
	Time Complexity: O(logn)
  	
	Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
	(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

	Find the minimum element.

	You may assume no duplicate exists in the array.
	
	---------------------------------------------------
	Example 1:

	Input: [3,4,5,1,2] 
	Output: 1
	
	---------------------------------------------------
	Example 2:

	Input: [4,5,6,7,0,1,2]
	Output: 0
	---------------------------------------------------
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
       
        if ( nums[nums.size()-1] > nums[0])
            return nums[0];
        
        int min = INT_MAX;
        int low = 0;
        int high = nums.size()-1;
        
        while ( low <= high ) {
            
            int mid = (low+high)/2;
            
            if ( nums[mid] < min )
                min = nums[mid];
            
            if ( nums[low] <= nums[mid] ) {
                
                if ( nums[low] <= nums[high] )
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            
            else {
                if ( nums[mid-1] <= nums[high] )
                    high = mid - 1;
                else
                    low = mid + 1;
            }
        }
        return min;
    }
};
