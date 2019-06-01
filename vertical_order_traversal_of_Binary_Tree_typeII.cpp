/*
Given a binary tree, return the vertical order traversal of its nodes values.
For each node at position (X, Y), its left and right children respectively will be at positions (X-1, Y-1) and (X+1, Y-1).

Running a vertical line from X = -infinity to X = +infinity, whenever the vertical line touches some nodes, we report the 
values of the nodes in order from top to bottom (decreasing Y coordinates).

If two nodes have the same position, then the value of the node that is reported first is the value that is smaller.

Return an list of non-empty reports in order of X coordinate.  Every report will have a list of values of nodes.

------------------------------------------------------------------------------------------------------------
Example 1:

Input: [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation: 
Without loss of generality, we can assume the root node is at position (0, 0):
Then, the node with value 9 occurs at position (-1, -1);
The nodes with values 3 and 15 occur at positions (0, 0) and (0, -2);
The node with value 20 occurs at position (1, -1);
The node with value 7 occurs at position (2, -2).

------------------------------------------------------------------------------------------------------------
Example 2:

Input: [1,2,3,4,5,6,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation: 
The node with value 5 and the node with value 6 have the same position according to the given scheme.
However, in the report "[1,5,6]", the node value of 5 comes first since 5 is smaller than 6.
------------------------------------------------------------------------------------------------------------
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void findMinMaxDistance(TreeNode* root, int *min, int *max, int distance) {
        
        if ( !root )
            return;
        
        if ( distance < *min )
            *min = distance;
        
        else if ( distance > *max )
            *max = distance;
        
        findMinMaxDistance(root->left, min, max, distance-1);
        findMinMaxDistance(root->right, min, max, distance+1);
    }
    
    void printVerticalOrder(TreeNode* root, vector<pair<int,int>>& v, int hd1, int hd2, int ver) {
        
        if ( !root )
            return;
        
        if ( hd1 == hd2 )
            v.push_back(make_pair(ver,root->val));
        
        printVerticalOrder(root->left, v, hd1, hd2-1, ver+1);
        printVerticalOrder(root->right, v, hd1, hd2+1, ver+1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        int min = 0; int max = 0;
        findMinMaxDistance(root, &min, &max, 0);
        
        vector<vector<int>> res(max-min+1);
        
        int count=0;
        for ( int i=min; i<=max; i++ ){
            vector<pair<int,int>> v;
            printVerticalOrder(root, v, i, 0, 0);
            sort(v.begin(), v.end());
            for(int j=0; j<v.size(); j++)
                res[count].push_back(v[j].second);
            count++;
        }
        return res;
    }
};
