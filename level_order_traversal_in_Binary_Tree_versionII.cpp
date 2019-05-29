/*
	Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

	For example:
	Given binary tree [3,9,20,null,null,15,7],
		3
	   / \
	  9  20
		/  \
	   15   7
	return its bottom-up level order traversal as:
	[
	  [15,7],
	  [9,20],
	  [3]
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
class Solution {
public:
    
    int helper(TreeNode* root) {
        
        if ( root == NULL)
            return 0;
        
        if ( root->left == NULL && root->right == NULL)
            return 1;
        
        return max(helper(root->left), helper(root->right)) + 1;
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        if ( root == NULL)
            return {};
        
        int level = helper(root);
        vector<vector<int>> ans(level);
        
        queue<TreeNode *> q;
        q.push(root);
        
        while (!q.empty()) {
            
            int size = q.size();
            
            for (int i=0; i <size; i++) {
                root = q.front();
                ans[level-1].push_back(root->val);
                q.pop();
                
                if ( root->left )
                    q.push(root->left);
                
                if ( root->right )
                    q.push(root->right);
            }
            
            level--;
        }
        return ans;
    }
};
