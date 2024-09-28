/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode*root,int&count,int maxi){
        if(!root)return ;
        if(root->val>=maxi){
            count++;
            maxi=root->val;
        }
        if(root->left)helper(root->left,count,maxi);
        if(root->right)helper(root->right,count,maxi);
        
        
    }
    int goodNodes(TreeNode* root) {
        
        // the traversal which i will be following is preorder which is nlr 
        int count=1;
        int maxi=root->val;
        if(root->left)helper(root->left,count,maxi);
        if(root->right)helper(root->right,count,maxi);
        return count;
    }
};