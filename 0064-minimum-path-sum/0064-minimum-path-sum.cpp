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

    // lets bring it down to what we know as tabular version of it 
    int tabular(vector<vector<int>>&grid,int row,int col){
        vector<vector<int>>dp(row+1,vector<int>(col+1,0));

        // lets come down to the main part which is the state diagram/equation
        // dp[row][col]=min sum to reach this cell form 0,0 

        dp[0][0]=grid[0][0];
        for(int i=1;i<=row;i++){
            dp[i][0]=dp[i-1][0]+grid[i][0];
        }

        for(int i=1;i<=col;i++){
            dp[0][i]=dp[0][i-1]+grid[0][i];
        }

        // now that i have initialized the array it is time to set up the loop 
        for(int i=1;i<=row;i++){
            for(int j=1;j<=col;j++){
                // now my meoised code will come here 
                int left=dp[i][j-1]+grid[i][j];
                int up=dp[i-1][j]+grid[i][j];

                dp[i][j]=min(left,up);


            }
        }

        return dp[row][col];
    }

    // now the only thing i can do to optimize this code further is to do the 
    // space optimization bringing the 2d array to 1d

    int so(vector<vector<int>>&grid,int row,int col){
        // vector<vector<int>>dp(row+1,vector<int>(col+1,0));
        vector<int>dp(col+1,0);

        // lets come down to the main part which is the state diagram/equation
        // dp[row][col]=min sum to reach this cell form 0,0 

        dp[0]=grid[0][0];
        for(int i=1;i<=col;i++){
            dp[i]=dp[i-1]+grid[0][i];
        }

        // now that i have initialized the array it is time to set up the loop 
        for(int i=1;i<=row;i++){
            vector<int>temp(col+1,0);
            temp[0]=dp[0]+grid[i][0];

            for(int j=1;j<=col;j++){
                // now my meoised code will come here 
                int left=temp[j-1]+grid[i][j];
                int up=dp[j]+grid[i][j];

                temp[j]=min(left,up);



            }
            dp=temp;
        }

        return dp[col];
    }



    int minPathSum(vector<vector<int>>& grid) {

        int m=grid.size();
        int n=grid[0].size();


        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));


        // return helper(grid,m-1,n-1,dp);
        // return tabular(grid,m-1,n-1);
        return so(grid,m-1,n-1);




        
    }
};