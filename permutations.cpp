/*
	Given a collection of distinct integers, return all possible permutations.
	
	Example:
		Input: [1,2,3]
		Output:
			[
  				[1,2,3],
  				[1,3,2],
  				[2,1,3],
  				[2,3,1],
  				[3,1,2],
  				[3,2,1]
			]
*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        int n = nums.size();
        int N = 1;
        
        for ( int i=1; i<=n; i++)
            N = N * i;
        
        cout << N << " ";
        vector<vector<int>> res;
        res.push_back(nums);
        
        for( int i=0; i<N-1; i++) {
            
            int j = nums.size()-1;
            for ( j=nums.size()-2; j >= 0; j-- ) {
                if ( nums[j] <= nums[j+1] )
                    break;
            }
            
            int k = j+1;
            while (j >= 0 && k < nums.size() && nums[j] <= nums[k])
                k++;
            
            if ( j>=0 && k-1 < nums.size())
                swap(nums[j], nums[k-1]);
            
            int lower = j + 1;
            reverse(nums.begin()+lower, nums.end());
            res.push_back(nums);
        }
        return res;
    }
};
