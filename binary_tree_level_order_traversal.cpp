/*
	Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

	For example:
	Given binary tree [3,9,20,null,null,15,7],
		3
	   / \
	  9  20
		/  \
	   15   7
	return its level order traversal as:
	[
	  [3],
	  [9,20],
	  [15,7]
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
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> v;
        if ( root == NULL )
            return v;
        
        queue<TreeNode *> q;
        
        q.push(root);
        
        while(!q.empty()) {
            
			vector<int> temp;
            int size = q.size();
            for(int i=0; i < size; i++){
                root = q.front();
                temp.push_back(root->val);
                q.pop();
                
                if ( root->left )
                    q.push(root->left);
                
                if ( root->right )
                    q.push(root->right);
            }
            
            v.push_back(temp);
        }
        return v;
    }
};
