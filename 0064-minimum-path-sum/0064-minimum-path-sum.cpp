class Solution {
public:
    int helper(vector<vector<int>>&grid,int row,int col,vector<vector<int>>&dp){
        if(row<0 || col<0)return INT_MAX;
        if(row==0&&col==0)return grid[0][0];

        if(dp[row][col]!=-1)return dp[row][col];

        // for every cell i have 2 options either to take right or take down
        int left=helper(grid,row,col-1,dp);
        if(left!=INT_MAX)left=left+grid[row][col];
        int up=helper(grid,row-1,col,dp);
        if(up!=INT_MAX)up=up+grid[row][col];

        return dp[row][col]= min(left,up);

    }
    int minPathSum(vector<vector<int>>& grid) {

        int m=grid.size();
        int n=grid[0].size();


        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));


        return helper(grid,m-1,n-1,dp);




        
    }
};