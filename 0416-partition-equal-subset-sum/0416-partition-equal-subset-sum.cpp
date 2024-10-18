class Solution {
public:

    int helper(vector<int>arr,int sum,int index,vector<vector<int>>&dp){
        
        if(index==arr.size()){
            if(sum==0)return 1;
            return 0;
        }
        
        if(sum<0)return 0;
        
        if(dp[index][sum]!=-1)return dp[index][sum];
        return dp[index][sum]= helper(arr,sum-arr[index],index+1,dp)||helper(arr,sum,index+1,dp);
    }
    bool canPartition(vector<int>& nums) {

        int total=accumulate(nums.begin(),nums.end(),0);
        if(total&1)return false;
        int target=total/2;

        vector<vector<int>>dp(nums.size()+1,vector<int>(target+1,-1));

        return helper(nums,target,0,dp);
        
    }
};