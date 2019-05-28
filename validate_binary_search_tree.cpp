/*
	Given a binary tree, determine if it is a valid binary search tree (BST).

	Assume a BST is defined as follows:

	The left subtree of a node contains only nodes with keys less than the node's key.
	The right subtree of a node contains only nodes with keys greater than the node's key.
	Both the left and right subtrees must also be binary search trees.

	------------------------------------------------------------------------------------------
	Example 1:

		2
	   / \
	  1   3

	Input: [2,1,3]
	Output: true
	
	
	------------------------------------------------------------------------------------------
	Example 2:

		5
	   / \
	  1   4
		 / \
		3   6

	Input: [5,1,4,null,null,3,6]
	Output: false
	Explanation: The root node's value is 5 but its right child's value is 4.
	
	------------------------------------------------------------------------------------------
*/

/*
	Approach: Perform using inorder traversal
	Time Complexity	:	O(n)
	Space Complexity:	O(n)
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
    bool isValidBST(TreeNode* root) {
        
        if (root == NULL)
            return true;
        
        double temp = -DBL_MAX;
        
        stack<TreeNode *> s;
        
        while(true) {
            
            while(root) {
                s.push(root);
                root = root->left;
            }
            
            if (s.empty())
                break;
            root = s.top();
            
            if ( temp >= root->val)
                return false;
            
            temp = root->val;
            s.pop();
            root = root->right;
        }

        return true;
    }
};
