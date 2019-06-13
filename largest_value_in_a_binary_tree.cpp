/*
	We need to find the largest value in each row of a binary tree.
 
	Example:
		Input: 
			  1
			 / \
			3   2
		   / \   \  
		  5   3   9 

		Output: [1, 3, 9]
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
    vector<int> largestValues(TreeNode* root) {
        
        if ( root == NULL)
            return {};
        
        queue<TreeNode *> q;
        q.push(root);
        vector<int> res;
        
        while ( !q.empty() ) {
            int max = INT_MIN;
            int size = q.size();
            for( int i=0; i<size; i++) {
                
                root = q.front();
                q.pop();
                
                if ( root->val > max )
                    max = root->val;
                
                if ( root->left )
                    q.push(root->left);
                
                if ( root->right )
                    q.push(root->right);
            }
            res.push_back(max);
        }
        return res;
    }
};
