class Solution {
public:
    int helper(int row,int col){
        // base case
        if(row==0 && col==0 )return 1;
        if(row<0 || col<0)return 0;

        return helper(row-1,col)+helper(row,col-1);
    }
    int memo(int row,int col,vector<vector<int>>&dp){
        if(row==0 && col==0 )return 1;
        if(row<0 || col<0)return 0;

        if(dp[row][col]!=-1)return dp[row][col];

        return dp[row][col]= memo(row-1,col,dp)+memo(row,col-1,dp);



    }
    int uniquePaths(int m, int n) {

        // return helper(m-1,n-1);
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return memo(m-1,n-1,dp);
        
    }
};