/*
  Given an array of integers, return indices of the two numbers such that they add up to a specific target.

  You may assume that each input would have exactly one solution, and you may not use the same element twice.

  Example:

  Given nums = [2, 7, 11, 15], target = 9,

  Because nums[0] + nums[1] = 2 + 7 = 9,
  return [0, 1].
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<pair<int, int>> temp;
        
        for(int i=0; i < nums.size(); i++)
            temp.push_back(make_pair(nums[i], i));
        
        sort(temp.begin(), temp.end());
        int begin = 0;
        int endv = temp.size()-1;
        
        while(begin < endv) {
            
            if ( temp[begin].first + temp[endv].first == target) 
                return {temp[begin].second, temp[endv].second};
            
            else if (temp[begin].first + temp[endv].first > target) 
                endv--;
            
            else
                begin++;
        }
        return {};
        
    }
};
