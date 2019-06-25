/*
	Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? 
	Find all unique triplets in the array which gives the sum of zero.

	Note:
		The solution set must not contain duplicate triplets.

	Example:
		Given array nums = [-1, 0, 1, 2, -1, -4],

			A solution set is:
			[
	  			[-1, 0, 1],
	  			[-1, -1, 2]
			]
*/
class Solution {
public:
    bool allZero(vector<int>& nums) {
        for( int i=0; i<nums.size(); i++) {
            if ( nums[i] != 0)
                return false;
        }
        return true;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        if ( nums.size() < 3)
            return {};
        
        if ( allZero(nums) )
            return {{0,0,0}};
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        
        for ( int i=0; i<nums.size(); i++) {
            int target = (-1) * nums[i];
            
            int lower = 0;
            int upper = nums.size()-1;
            
            while ( lower < upper ) {
                if ( lower != i && upper != i ) {
                    
                    if ( nums[lower] + nums[upper] == target )  {
                        
                        vector<int> v;
                        if ( i < lower ) {
                            v.push_back(nums[i]);
                            v.push_back(nums[lower]);
                            v.push_back(nums[upper]);
                        }
                    
                        else if ( i > lower && i < upper ) {
                            v.push_back(nums[lower]);
                            v.push_back(nums[i]);
                            v.push_back(nums[upper]);
                        }
                    
                        else {
                            v.push_back(nums[lower]);
                            v.push_back(nums[upper]);
                            v.push_back(nums[i]);
                        }
                        ans.push_back(v);
                        lower++;
                        upper--;
                    }
                    
                    else if ( nums[lower] + nums[upper] > target )
                        upper--;
                    
                    else
                        lower++;
                }
                
                else {
                    if ( lower == i )
                        lower++;
                    else if ( upper == i )
                        upper--;
                }
            }
        }   
		
        set<vector<int>> s;
        
        for ( int i=0; i<ans.size(); i++) 
            s.insert(ans[i]);

        ans.clear();
        for ( auto itr = s.begin(); itr != s.end(); itr++) 
            ans.push_back(*itr);
        
        return ans;
    }
};
