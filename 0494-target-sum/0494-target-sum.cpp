class Solution {
public:
    int helper(vector<int>&nums,int index,int target){
        if(index==nums.size()){
            if(target==0)return 1;
            return 0;
        }
        
        return helper(nums,index+1,target-nums[index])+helper(nums,index+1,target+nums[index]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {

        // for every element i have 2 choices either to add 
        //  or subtract - 

        return helper(nums,0,target);
        
    }
};