/*
	Given an array of strings, group anagrams together.

	Example:
		Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
		Output:
			[
	  			["ate","eat","tea"],
	  			["nat","tan"],
	  			["bat"]
			]
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<string, int> s;
        int count = 0;
        
        for ( int i=0; i<strs.size(); i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            if ( s.find(temp) == s.end()) {
                s.insert(make_pair(temp, count));
                count++;
            }
        }
        
        vector<vector<string>> res(count);
        
		for ( int i=0; i<strs.size(); i++ ) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            auto itr = s.find(temp);
            int index = (*itr).second;
            res[index].push_back(strs[i]);
        }
        return res;
    }
};
