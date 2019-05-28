/*
	Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

	For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

		1
	   / \
	  2   2
	 / \ / \
	3  4 4  3


	But the following [1,2,2,null,3,null,3] is not:

		1
	   / \
	  2   2
	   \   \
	   3    3
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
    
    bool helper(TreeNode* root1, TreeNode* root2) {
        
        
        if (( root1 == NULL && root2) || (root2 == NULL && root1))
            return false;
        
        if(root1 == NULL && root2 == NULL)
            return true;
        
        if (root1->val == root2->val)
            return helper(root1->left, root2->right) && helper(root1->right, root2->left);
    
        return false;
    }
    
    bool isSymmetric(TreeNode* root) {
        if ( root == NULL)
            return true;
        return helper(root->left, root->right);    
    }
};
