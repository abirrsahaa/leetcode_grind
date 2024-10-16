class Solution {
public:

    int helper(vector<vector<int>>& obstacleGrid,int row,int col){
        if(row<0 || col<0)return 0;
        if(obstacleGrid[row][col]==1)return 0;
        if(row==0 && col==0 )return 1;

        return helper(obstacleGrid,row-1,col)+helper(obstacleGrid,row,col-1);
    }

    // lets come to memo
    int memo(vector<vector<int>>& obstacleGrid,int row,int col,vector<vector<int>>&dp){
        if(row<0 || col<0)return 0;
        if(obstacleGrid[row][col]==1)return 0;
        if(row==0 && col==0 )return 1;
        if(dp[row][col]!=-1)return dp[row][col];

        return dp[row][col]= memo(obstacleGrid,row-1,col,dp)+memo(obstacleGrid,row,col-1,dp);                
    }


    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();

        // return helper(obstacleGrid,m-1,n-1);
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return memo(obstacleGrid,m-1,n-1,dp);
        
    }
};