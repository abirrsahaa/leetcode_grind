class Solution {
public:
    int helper(vector<int>&coins,int amount,int index,vector<vector<int>>&dp){
        if(amount==0)return 0;
        if(index==coins.size()){
            if(amount==0)return 0;
            return INT_MAX;
        }
        if(amount<0)return INT_MAX;
        if(dp[index][amount]!=-1)return dp[index][amount];

        // now is the time for my choices
        int take=helper(coins,amount-coins[index],index,dp);
        if(take!=INT_MAX)take+=1;
        int not_take=helper(coins,amount,index+1,dp);
        return dp[index][amount]= min(take,not_take);
    }
    int coinChange(vector<int>& coins, int amount) {

        // ideally i should be first trying this with a greedy approach 
        // but pehle brute force se hi chalte hai fir !!

        // at every index again i have 2 choices either to take it or to not take it 

        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        int ans=helper(coins,amount,0,dp);
        if(ans!=INT_MAX)return ans;
        return -1;
        
    }
};