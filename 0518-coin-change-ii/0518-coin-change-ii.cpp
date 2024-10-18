class Solution {
public:
    int helper(vector<int>&coins,int amount,int index,vector<vector<int>>&dp){



// that is why it is suggested that always formulate the top_down in the top-down format
// there is a reason why it is said so 
        // these are my base cases 
        if(amount==0)return 1;
        if(index==0){
            if((amount%coins[0])==0)return 1;
            return 0;
        }
        if(amount<0)return 0;


        if(dp[index][amount]!=-1)return dp[index][amount];

        // now is the time for my choices
        int take=helper(coins,amount-coins[index],index,dp);
        // if(take!=INT_MAX)take+=1;
        int not_take=helper(coins,amount,index-1,dp);
        return dp[index][amount]= take+not_take;
    }    
    int change(int amount, vector<int>& coins) {


        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));


        return helper(coins,amount,coins.size()-1,dp);
        
    }
};