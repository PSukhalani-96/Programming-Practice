/*
	Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
	Example 1:
	Input:
		3
	   / \
	  9  20
		/  \
	   15   7
	Output: [3, 14.5, 11]
	Explanation:
	The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
	Note:
	The range of node's value is in the range of 32-bit signed integer.
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
    vector<double> averageOfLevels(TreeNode* root) {
        
        if (root == NULL)
            return {};
        
        vector<double> ans;
        queue<TreeNode *> q;
        
        q.push(root);
        
        while (!q.empty()) {
            
            int size = q.size();
            double sum = 0;
            
            for ( int i=0; i < size; i++) {
                root = q.front();
                sum += root->val;
                q.pop();
                
                if ( root->left )
                    q.push(root->left);
                
                if ( root->right )
                    q.push(root->right);
            }
            
            sum = sum / size;
            ans.push_back(sum);
        }
        
        return ans;
    }
};
