/*
    Given two binary trees, write a function to check if they are the same or not.
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if ( p == NULL && q == NULL )
            return true;
        
        if (( p == NULL && q != NULL) || ( q == NULL && p != NULL))
            return false;
        
        if ( p->val == q->val )
            return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
        
        return false;
        
    }
};
