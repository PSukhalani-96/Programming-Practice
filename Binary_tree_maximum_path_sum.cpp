/*
  Given a non-empty binary tree, find the maximum path sum.

  For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the 
  parent-child connections. The path must contain at least one node and does not need to go through the root.

  Example 1:
    Input: [1,2,3]

         1
        / \
       2   3

    Output: 6
  
  Example 2:
    Input: [-10,9,20,null,null,15,7]

        -10
        / \
       9  20
       /  \
      15   7

  Output: 42
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
   
    int maxPSum(TreeNode *root, int *max_val) {
        
        if ( root == nullptr )
            return 0;
        
        int sum1 = maxPSum(root->left, max_val);
        int sum2 = maxPSum(root->right, max_val);
        
        int max1 = max(max(sum1, sum2)+root->val, root->val);
        int max2 = max(max1, sum1+sum2+root->val);
        *max_val  = max(*max_val, max2);
        
        return max1;    // This is the key statement to solve this problem.
    }
    
    int maxPathSum(TreeNode* root) {
        
        int max_val = INT_MIN;
        maxPSum(root, &max_val);
        return max_val;
    }
};   
