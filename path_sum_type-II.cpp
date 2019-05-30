/*
	Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

	Note: A leaf is a node with no children.

	Example:

	Given the below binary tree and sum = 22,

		  5
		 / \
		4   8
	   /   / \
	  11  13  4
	 /  \    / \
	7    2  5   1
	Return:

	[
	   [5,4,11,2],
	   [5,8,4,5]
	]
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
// **Note: It's a kind of a simple Backtracking Problem.

class Solution {
public:
	void helper(TreeNode *root, int sum, vector<int> &path, vector<vector<int>> &res) {
        
        if ( !root )
            return ;
        
        path.push_back(root->val);
        
        if ( !root->left && !root->right && sum-root->val == 0)
            res.push_back(path);
        
        helper(root->left,  sum - root->val, path, res);
        helper(root->right, sum - root->val, path, res);
        path.pop_back();
    
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        
        vector<int> path;
        vector<vector<int>> res;
        helper(root, sum, path, res);
        return res;
    }
};
