class Solution {
public:
    void helper(vector<int>&nums,int&ans,int index,int curr){
        if(index==nums.size()){
            ans+=curr;
            return;
        }
        // include
        // curr=curr^nums[index];
        helper(nums,ans,index+1,curr^nums[index]);
        // exclude
        helper(nums,ans,index+1,curr);
    }
    int subsetXORSum(vector<int>& nums) {
        int ans=0;
        helper(nums,ans,0,0);
        return ans;
        
    }
};