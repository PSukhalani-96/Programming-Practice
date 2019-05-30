/*
	Given a binary tree, return the preorder traversal of its nodes' values.
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
    vector<int> preorderTraversal(TreeNode* root) {
        
        if ( root == NULL)
            return {};
        
        vector<int> ans;
        stack<TreeNode *> s;
        
        s.push(root);
        
        while (!s.empty()) {
            
            root = s.top();
            ans.push_back(root->val);
            s.pop();
            
            if ( root->right )
                s.push(root->right);
            
            if ( root->left )
                s.push(root->left);
        }
        
        return ans;
    }
};
