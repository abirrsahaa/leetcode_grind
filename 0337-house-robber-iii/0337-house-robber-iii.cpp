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
//  check the tle submission for the reccursive approach 
// although one thing here is the fact that in recursive preorder worked 
// but when we use dp we normally use a bottom up approCH 
// as a result we find dependibility in children nodes
// this postorder is the way to these problem when we have to do dp on trees

// this is the first problem on dp on trees
// and the first time i am meoizing with the help of a map 

pair<int,int> helper(TreeNode* root){
    if(!root)return {0,0};

    // post order traversal karo 
    // pehle sub trees solve karke aoo
    pair<int,int>left=helper(root->left);
    pair<int,int>right=helper(root->right);

    // agar mai root ko leta hu toh children ko nahi le sakta 
    int liya=root->val+left.second+right.second;

    // agar mai nahi leta hu then children ko le bhi sakta hu and nahi bhi 
    int nahi_liya=max(left.first,left.second)+max(right.first,right.second);

    return {liya,nahi_liya}; //dp memoize stuff har step ka liya or nahi liya ka mapping
}
class Solution {
public:
    int rob(TreeNode* root) {
        pair<int,int>ans=helper(root);
        return max(ans.first,ans.second);
    }
};