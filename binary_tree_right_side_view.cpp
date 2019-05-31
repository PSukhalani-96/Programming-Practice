/*
	Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see 
	ordered from top to bottom.
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
    vector<int> rightSideView(TreeNode* root) {
        
        if ( !root )
            return {};
        vector<int> v;
        queue<TreeNode *> q;
        
        q.push(root);
        while ( !q.empty()) {
            int size = q.size();
            for ( int i=0; i<size; i++) {
                root = q.front();
                q.pop();
                if ( i == size-1)
                    v.push_back(root->val);
                
                if ( root->left )
                    q.push(root->left);
                
                if ( root->right )
                    q.push(root->right);
            }
        }
        return v;
    }
};
