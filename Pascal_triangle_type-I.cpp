/*
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
-----------------------------------------------------
Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
-----------------------------------------------------
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        if (numRows <= 0)
            return {};
        
        vector<vector<int>> ans(numRows);
        
        for (int i=0; i < numRows; i++) {
            for(int j=0; j <= i; j++) {
                
                if ( i == j || j == 0)
                    ans[i].push_back(1);
                else  {
                    int temp = ans[i-1][j] + ans[i-1][j-1];
                    ans[i].push_back(temp);
                }
            }
        }
        return ans;
    }
};

