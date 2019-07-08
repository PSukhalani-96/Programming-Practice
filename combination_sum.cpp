/*
	Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique 
	combinations in candidates where the candidate numbers sums to target.

	The same repeated number may be chosen from candidates unlimited number of times.

	Note:
		All numbers (including target) will be positive integers.
		The solution set must not contain duplicate combinations.

	Example 1:
		Input: candidates = [2,3,6,7], target = 7,
		A solution set is:
			[
  				[7],
  				[2,2,3]
			]

	Example 2:
		Input: candidates = [2,3,5], target = 8,
		A solution set is:
			[
  				[2,2,2,2],
  				[2,3,3],
  				[3,5]
			]
*/

class Solution {
public:
    void find_sum(vector<int> candidates, int index, vector<vector<int>> &res, vector<int> tmp, int target) {
        
        if ( target == 0 ) {
            res.push_back(tmp);
            return;
        }
        
        if ( target < 0 || index == candidates.size())
            return;
        
        tmp.push_back(candidates[index]);
        find_sum(candidates, index, res, tmp, target-candidates[index]);
        tmp.pop_back();
        find_sum(candidates, index+1, res, tmp, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    
        vector<vector<int>> res;
        vector<int> tmp;
        find_sum(candidates,0, res, tmp, target);
        return res;
    }
};
