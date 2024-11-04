// i am fucking surprised to know the fact that 
// i havent solved this problem 

class Solution {
public:
    int helper(vector<int>&nums,int index,int prev,vector<vector<int>>&dp){
        if(index==nums.size())return 0;
        if(dp[index][prev+1]!=-1)return dp[index][prev+1];

        int not_taken=0+helper(nums,index+1,prev,dp); //agr nhi liya toh 
        int taken=0;
        if(prev==-1||nums[index]>nums[prev]){
            taken=1+helper(nums,index+1,index,dp); //agr liya toh
        }
        return dp[index][prev+1]= max(not_taken,taken);
    }
    // need to do the memo part which is the most important 
    
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return helper(nums,0,-1,dp);
    }
};