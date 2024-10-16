class Solution {
public:
// simple recursive approach 
    int helper(int row,int col){
        // base case
        if(row==0 && col==0 )return 1;
        if(row<0 || col<0)return 0;

        return helper(row-1,col)+helper(row,col-1);
    }

// simple memoisation 
    int memo(int row,int col,vector<vector<int>>&dp){
        if(row==0 && col==0 )return 1;
        if(row<0 || col<0)return 0;

        if(dp[row][col]!=-1)return dp[row][col];

        return dp[row][col]= memo(row-1,col,dp)+memo(row,col-1,dp);
    }

// turning the memoisation code into tabulation 

    int tabulation(int row,int col){
        vector<vector<int>>dp(row+1,vector<int>(col+1,0));
        
        // i am fucking up here in the base case
        for(int i=0;i<=row;i++){
            dp[i][0]=1;
        }
        for(int i=0;i<=col;i++){
            dp[0][i]=1;
        }

        for(int i=1;i<=row;i++){
            for(int j=1;j<=col;j++){
                // if(j==0)dp[i][j]=dp[i-1][j];
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }

        return dp[row][col];
    }

    int uniquePaths(int m, int n) {

        // return helper(m-1,n-1);
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        // return memo(m-1,n-1,dp);
        return tabulation(m-1,n-1);
        
    }
};