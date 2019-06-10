/*
	Given a binary tree, return the postorder traversal of its nodes' values.

	Example:
		Input: [1,null,2,3]
	   	1
		 \
		  2
		 /
	    3

		Output: [3,2,1]
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
    vector<int> postorderTraversal(TreeNode* root) {
        
        if ( root == nullptr)
            return {};
        
        stack<TreeNode* > s;
        vector<int> postorder;
        
        TreeNode* previous = nullptr;
        
        s.push(root);
        root = root->left;
        while ( !s.empty() ) {
            
            while ( root ) {
                s.push(root);
                root = root->left;
            }
            
            while ( root == nullptr && !s.empty() ) {
                root = s.top();
                if ( root->right == NULL || root->right == previous ) {
                    postorder.push_back(root->val);
                    s.pop();
                    previous = root;
                    root = nullptr;
                }
                else
                    root = root->right;
            } 
        }
        return postorder;
    }
};
