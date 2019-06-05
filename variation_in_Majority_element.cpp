/*
	Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

	Note: The algorithm should run in linear time and in O(1) space.

	Example 1:
		Input: [3,2,3]
		Output: [3]

	Example 2:
		Input: [1,1,1,3,3,2,2,2]
		Output: [1,2]
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int maj_index_one = 0, maj_index_sec = 1;
        int count1 = 0, count2 = 0;
        
        for ( int i=0; i<nums.size(); i++) {
            
            if ( nums[maj_index_one] == nums[i])
                count1++;
            
            else if ( nums[maj_index_sec] == nums[i])
                count2++;
            
            else if ( count1 == 0 ) {
                maj_index_one = i;
                count1 = 1;
            }
            
            else if ( count2 == 0 ) {
                maj_index_sec = i;
                count2 = 1;
            }
            
            else {
                count1--;
                count2--;
            }
        }
        
        vector<int> res;
        
        count1 = count2 = 0;
        for ( int i=0; i<nums.size(); i++) {
            
            if ( nums[i] == nums[maj_index_one])
                count1++;
            
            else if ( nums[i] == nums[maj_index_sec])
                count2++;
        }
        
        if ( count1 > nums.size() / 3 )
            res.push_back(nums[maj_index_one]);
        
        if ( count2 > nums.size() / 3 )
            res.push_back(nums[maj_index_sec]);
        
        return res;
    }
};
