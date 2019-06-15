/*
	Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear 
	exactly twice. Find the two elements that appear only once.

	Example:
		Input:  [1,2,1,3,2,5]
		Output: [3,5]
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        vector<int> res;
        int xor_res = 0;
        
        for ( int i=0; i<nums.size(); i++)
            xor_res = xor_res ^ nums[i];
        
        int set_bit = xor_res & ~(xor_res - 1);
        
        int a = 0, b = 0;
        
        for ( int i=0; i<nums.size(); i++) {
            if ( set_bit & nums[i] )
                a = a ^ nums[i];
            else
                b = b ^ nums[i];
        }
        
        res.push_back(a);
        res.push_back(b);
        return res;
    }
};
