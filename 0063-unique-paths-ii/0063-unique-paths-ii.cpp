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

    // lets come to tabulation
    int tabulation(vector<vector<int>>& obstacleGrid,int row,int col){
        if(obstacleGrid[0][0])return 0;
        vector<vector<int>>dp(obstacleGrid.size()+1,vector<int>(obstacleGrid[0].size()+1,0));

        for(int i=0;i<obstacleGrid.size();i++){
            if(obstacleGrid[i][0])break;
            dp[i][0]=1;
        }

        for(int i=0;i<obstacleGrid[0].size();i++){
            if(obstacleGrid[0][i])break;
            dp[0][i]=1;
        }

        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();

        // formulating the tabulation
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]!=1)dp[i][j]=dp[i-1][j]+dp[i][j-1];
                else dp[i][j]=0;
            }
        }
        return dp[m-1][n-1];
    }


    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();

        // return helper(obstacleGrid,m-1,n-1);
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        // return memo(obstacleGrid,m-1,n-1,dp);/
        return tabulation(obstacleGrid,m,n);
        
    }
};