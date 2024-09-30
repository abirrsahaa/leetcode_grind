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
    void helper(TreeNode* root,int&ans,int curr){
        if(!root)return ;
        if(!root->left&&!root->right){
            curr=curr*10+root->val;
            ans+=curr;
            return;
        }
        helper(root->left,ans,curr*10+root->val);
        helper(root->right,ans,curr*10+root->val);
    }
    int sumNumbers(TreeNode* root) {
        int ans=0;
        int curr=0;
        helper(root,ans,curr);
        return ans;
        
    }
};