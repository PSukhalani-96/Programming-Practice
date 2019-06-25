/*
	Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum 
	is equal to the given target.

	Example 1:

		Input: 
					5
				   / \
				  3   6
				 / \   \
				2   4   7

		Target = 9
		Output: True
 
	Example 2:

		Input: 
					5
				   / \
				  3   6
				 / \   \
				2   4   7

		Target = 28
		Output: False
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
    
    void inorder(vector<int> &v, TreeNode *root) {
        if ( root ) {
            inorder(v, root->left);
            v.push_back(root->val);
            inorder(v, root->right);
        }
        else
            return;
    }
    
    bool findTarget(TreeNode* root, int k) {
        
        vector<int> v;
        inorder(v, root);
        
        int lower = 0;
        int upper = v.size()-1;
        
        while ( lower < upper ) {
            
            if ( v[lower] + v[upper] == k ) 
                return true;
            
            else if ( v[lower] + v[upper] > k )
                upper--;
            
            else
                lower++;
            
        }
        return false; 
    }
};
