/*
	Given two arrays, write a function to compute their intersection.

	Example 1:
	Input: nums1 = [1,2,2,1], nums2 = [2,2]
	Output: [2,2]
	
	Example 2:	
	Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
	Output: [4,9]
	Note:

	Each element in the result should appear as many times as it shows in both arrays.
	The result can be in any order.
*/

class Solution {
public:
    
    vector<int> helper(vector<int> nums1, vector<int> nums2) {
        
        vector<int> res;
        map<int, int> mp;
        
        for (int i=0; i<nums2.size(); i++) {
            if ( mp.find(nums2[i]) != mp.end()) {
                map<int,int>::iterator itr = mp.find(nums2[i]);
                itr->second++;
            }
            else 
                mp.insert(make_pair(nums2[i],1));
         }
     
        for (int i=0; i<nums1.size(); i++) {
            if ( mp.find(nums1[i]) != mp.end() ) {
                map<int,int>::iterator itr = mp.find(nums1[i]);
                res.push_back(nums1[i]);
                itr->second--;
                if(itr->second == 0)
                    mp.erase(itr);
            }
        }
        return res;
    }
    
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        if (nums1.size()==0 || nums2.size() == 0)
            return {};
            
        bool firstSorted  = true;
        bool secondSorted = true;
        
        for (int i=0; i<nums1.size()-1; i++) {
            if ( nums1[i] > nums1[i+1]) {
                firstSorted = false;
                break;
            }
        }
        
        for (int i=0; i<nums2.size()-1; i++) {
            if ( nums2[i] > nums2[i+1 ]) {
                secondSorted = false;
                break;
            }
        }
        
        if ( !firstSorted && !secondSorted ) {
            if ( nums1.size() > nums2.size() ){
                sort(nums2.begin(), nums2.end());
                secondSorted == true;
            }
            else {
                sort(nums1.begin(), nums1.end());
                firstSorted == true;   
            }
        }
        
        vector<int> res;
        
        if ( firstSorted )
            res = helper(nums1, nums2);
        
        else
            res = helper(nums2, nums1);
        
        return res;
        
    }
};
