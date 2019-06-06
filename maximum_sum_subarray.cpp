/*
	Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum 
	and return its sum.

	Example:
		Input: [-2,1,-3,4,-1,2,1,-5,4],
		Output: 6
		Explanation: [4,-1,2,1] has the largest sum = 6.
*/

// Approach-1

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int sum = 0;
        int max_sum = INT_MIN;
        
        for ( int i=0; i<nums.size(); i++) {
            if ( sum < 0 ) {
                if ( nums[i] > sum || nums[i] > 0 )
                    sum = nums[i];
            }
            else
                sum = sum+nums[i];
            max_sum = max(max_sum, sum);
        }
        return max_sum;
    }
};
