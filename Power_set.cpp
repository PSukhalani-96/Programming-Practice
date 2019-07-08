/*
	Given a set of distinct integers, nums, return all possible subsets (the power set).

	Note: The solution set must not contain duplicate subsets.

	Example:
		Input: nums = [1,2,3]
		Output:
		[
			[3],
	  		[1],
	  		[2],
	  		[1,2,3],
	  		[1,3],
	  		[2,3],
	  		[1,2],
	  		[]
		]	
*/

// Solution-1 
// Time Complexity: T(N) = 2T(N-1) + O(1) = O(2^N).
// Approach: Backtracking

class Solution {
public:
    void find_subsets(vector<int> nums, int index, vector<int> tmp, vector<vector<int>>& res) {
        
        if ( index == nums.size()) {
            res.push_back(tmp);
            return;
        }
        
        tmp.push_back(nums[index]);
        find_subsets(nums, index+1, tmp, res);
        tmp.pop_back();
        find_subsets(nums, index+1, tmp, res);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
    
        vector<vector<int>> res;
        vector<int> tmp;
        find_subsets(nums,0, tmp, res);
        return res;
    }
};   


// Solution-2
// Time Complexity: O(N^2)
// Approach: Bit Manipulation

class Solution {
public:

    // Bit Manipulation leads to O(N^2).
    // [] [1] [2] [1,2] [3] [1,3] [2,3] [1,2,3]
    // element 1 is occuring once in every two consecutive subsets
    // element 2 is occurring twice in every four consecutive subsets
    // element 3 is occuring four times in every eight consecutive subsets.
    
    vector<vector<int>> subsets(vector<int>& nums) {
    
        int N = nums.size();
        int z = 1 << N;
        vector<vector<int>> res(z);
        
        for ( int i=0; i<z; i++ ){
            for ( int j=0; j<N; j++ ) {
                if ( ((i >> j)) & 1 )
                    res[i].push_back(nums[j]);
            }
        }
        return res;
    }
};
