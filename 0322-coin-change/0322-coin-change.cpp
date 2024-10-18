class Solution {
public:
    int helper(vector<int>&coins,int amount,int index,vector<vector<int>>&dp){

        // these are my base cases 
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
    // now that i have memoised it it is now time to come down to the tabular or the bottom-up approach

    int tabulation(vector<int>&coins,int amount){
        // defining my dp array
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,INT_MAX));

        // now deciding the initial state of my table 
        for(int i=0;i<coins.size();i++){
            dp[i][0]=0;
        }

        // for every possible value of amount we have found out min no of coins using only the first coin 

        for (int j = 0; j <= amount; j++) {
    if (j % coins[0] == 0) {
        dp[0][j] = j / coins[0];
    }
}
//another base case of the first row that if that amount is there we would need a 1 coin and if not we cannot have any combination 

        // now formulating the loops 
        for(int i=1;i<coins.size();i++){
            for(int j=0;j<=amount;j++){
                int take=INT_MAX;
                if(coins[i]<=j){
                    take=dp[i][j-coins[i]];
                    if(take!=INT_MAX)take+=1;
                }
                int not_take=dp[i-1][j];

                dp[i][j]=min(take,not_take);
            }
        }

        return dp[coins.size()-1][amount];
    }

    int coinChange(vector<int>& coins, int amount) {

        // ideally i should be first trying this with a greedy approach 
        // but pehle brute force se hi chalte hai fir !!

        // at every index again i have 2 choices either to take it or to not take it 

        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        // int ans=helper(coins,amount,0,dp);
        int ans=tabulation(coins,amount);
        if(ans!=INT_MAX)return ans;
        return -1;
        
    }
};