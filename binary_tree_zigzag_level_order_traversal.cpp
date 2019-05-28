/*
	******************Need to be improved*******************
	
	Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

	For example:
	Given binary tree [3,9,20,null,null,15,7],
		3
	   / \
	  9  20
		/  \
	   15   7
	return its zigzag level order traversal as:
	[
	  [3],
	  [20,9],
	  [15,7]
	]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
     
       vector<vector<int>> v;
        if ( root == NULL )
            return v;
        
        queue<TreeNode *> q;
        
        q.push(root);
        
        while(!q.empty()) {
            
            vector<int> temp;
            int size = q.size();
            for(int i=0; i < size; i++){
                root = q.front();
                temp.push_back(root->val);
                q.pop();
                
                if ( root->left )
                    q.push(root->left);
                
                if ( root->right )
                    q.push(root->right);
            }
            
            v.push_back(temp);
        }
        
        for(int i=0; i < v.size(); i++) {
            if ( i % 2 ){
                int low = 0;
                int high = v[i].size()-1;
                while(low < high){
                    int temp = v[i][low];
                    v[i][low] = v[i][high];
                    v[i][high] = temp;
                    low++;
                    high--;
                }
            }
        }
        return v;
    }
};
