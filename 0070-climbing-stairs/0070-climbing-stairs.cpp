class Solution {
public:
    int memo(int n,vector<int>&dp){
        if(n==0||n==1||n==2)return n;
        if(dp[n]!=-1)return dp[n];

        return dp[n]=memo(n-1,dp)+memo(n-2,dp);

    }
    int iterative(int n){
        if(n==0||n==1||n==2)return n;
        vector<int>dp(n+1,0);
        dp[1]=1;
        dp[2]=2;
        // if()
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        // return memo(n,dp);
        return iterative(n);
        
    }
};