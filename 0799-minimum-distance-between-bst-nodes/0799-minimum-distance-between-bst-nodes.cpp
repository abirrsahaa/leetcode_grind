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

//  previously i used a o(n) space and another 0(n) iteration 
// this apaproach discards both of this and calculates it on the fly 
// although the intuition still remains same it is just how we 
// optimize our code further 
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        int diff = INT_MAX;
        TreeNode* prev = nullptr;
        
        helper(root, prev, diff);
        
        return diff;
    }

    void helper(TreeNode* node, TreeNode*& prev, int& diff) {
        if (!node) return;
        
        // In-order traversal (left -> node -> right)
        helper(node->left, prev, diff);
        
        if (prev != nullptr) {
            diff = min(diff, node->val - prev->val);
        }
        
        prev = node; // Update the previous node
        
        helper(node->right, prev, diff);
    }
};
