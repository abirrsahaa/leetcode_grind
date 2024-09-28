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

//  lets first discuss the algo coming into mind 
// first 
// traverse through all the nodes get the value and then store it in array 
// sort it and get the min diff in 0(n);


// else we cannot get the two smaller number at that doesnt ensure it 
// i am going witn inorder and then o(n);

// OPTIMIZATION-->
// what we can do is in inorder when we are backtracking we can calculate the min diff
// so as to reduce the another iteration and aslo to sve in space 

class Solution {
public:
    void helper(TreeNode* root,vector<int>&track){
        if(!root->left&&!root->right){
            track.push_back(root->val);
            return;
        }
        if(root->left)helper(root->left,track);
        // cout<<"data"<<root->val<<endl;
        track.push_back(root->val);
        if(root->right)helper(root->right,track);
    }
    int minDiffInBST(TreeNode* root) {

        int diff=INT_MAX;
        vector<int>track;
        helper(root,track);
        // cout<<"printing the inorder"<<endl;
        // for(auto i:track)cout<<i<<" ";
        // cout<<endl;
        for(int i=1;i<track.size();i++){
            diff=min(diff,abs(track[i]-track[i-1]));
        }
        return diff;
        
    }
};