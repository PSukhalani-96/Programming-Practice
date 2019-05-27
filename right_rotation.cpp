/*
	Given an array, rotate the array to the right by k steps, where k is non-negative.

	Example 1:
	-----------------------------------------------------
	Input: [1,2,3,4,5,6,7] and k = 3
	Output: [5,6,7,1,2,3,4]
	Explanation:
	rotate 1 steps to the right: [7,1,2,3,4,5,6]
	rotate 2 steps to the right: [6,7,1,2,3,4,5]
	rotate 3 steps to the right: [5,6,7,1,2,3,4]
	
	Example 2:
	-----------------------------------------------------
	Input: [-1,-100,3,99] and k = 2
	Output: [3,99,-1,-100]
	Explanation: 
	rotate 1 steps to the right: [99,-1,-100,3]
	rotate 2 steps to the right: [3,99,-1,-100]
*/

class Solution {
public:
    
    int gcd(int a, int b) {
        if ( b==0 )
            return a;
        return gcd(b, a%b);
    }
    void rotate(vector<int>& nums, int k) {
        
		if (nums.size() <= 1)
            return;
        
        if ( k > nums.size())
            k = k - nums.size();
        
        int temp;
        
        int n = gcd(nums.size(), k);
        
        for (int i=0; i<n; i++) {
            
            temp = nums[nums.size()-1-i];
            int j = nums.size() - 1 - i;
            
            while (true) {
                int l = j - k;
                
                if ( l < 0 )
                    l = l + nums.size();
                
                if ( l == nums.size()-i-1 )
                    break;
                
                nums[j] = nums[l];
                j = l;
            }
            
            nums[j] = temp;
        }
    }
};
