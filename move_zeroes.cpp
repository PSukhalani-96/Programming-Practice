/*
	Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the 
	non-zero elements.

	Example:
		Input: [0,1,0,3,12]
		Output: [1,3,12,0,0]
*/

// Approach-1

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       
        for(int i=1; i<nums.size(); i++) {
            int j=i;
            int temp = nums[j];
            
            while ( j>0 && nums[j-1] == 0) {
                nums[j] = nums[j-1];
                j--;
            }
            nums[j] = temp;
        }
	}
};

// Approach-2

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
               
        int curr_zero = 0;
        for(int i=0; i<nums.size(); i++) {
            if ( nums[i] != 0) {
                nums[curr_zero] = nums[i];
                curr_zero++;
            }
        }
        for(int i=curr_zero; i<nums.size(); i++)
            nums[i] = 0;
    }
};
