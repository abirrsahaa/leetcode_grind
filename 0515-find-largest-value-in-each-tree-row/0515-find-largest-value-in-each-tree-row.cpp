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
    vector<int> largestValues(TreeNode* root) {
        // simple bfs traversal lagao and jab tak na null ajaye 
        // just track the max element and when you encounter a null
        // just make sure that you have encountered a level and store 
        vector<int>ans;
        if(!root)return ans;
        queue<TreeNode*>mpp;
        ans.push_back(root->val);
        mpp.push(root);
        mpp.push(NULL);
        while(!mpp.empty()){
            int maxi=INT_MIN;
            while(mpp.front()){
                if(mpp.front()->left){
                    maxi=max(maxi,mpp.front()->left->val);
                    mpp.push(mpp.front()->left);
                }
                if(mpp.front()->right){
                    maxi=max(maxi,mpp.front()->right->val);
                    mpp.push(mpp.front()->right);  
                }
                mpp.pop();
            }
            if(!mpp.front()){
                mpp.pop();
                if(!mpp.empty()){
                    ans.push_back(maxi);
                    mpp.push(NULL);
                }
            }
        }

        return ans;
        
    }
};