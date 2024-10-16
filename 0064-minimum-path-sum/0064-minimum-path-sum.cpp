class Solution {
public:
    int solveusingrec(vector<vector<int>>& grid,int curr_m,int curr_n){
        // base case 
        if(curr_m==0&&curr_n==0)return grid[0][0];
        if(curr_m<0)return INT_MAX;
        if(curr_n<0)return INT_MAX;


        int left=INT_MAX,down=INT_MAX;
        int ansl=solveusingrec(grid,curr_m-1,curr_n);
        if(ansl!=INT_MAX)left=grid[curr_m][curr_n]+ansl;
        int ansd=solveusingrec(grid,curr_m,curr_n-1);
        if(ansd!=INT_MAX)down=grid[curr_m][curr_n]+ansd;


        return min(left,down);
    }

      int solveusingmemo(vector<vector<int>>& grid,int curr_m,int curr_n,vector<vector<int>>&dp){
        // base case 
        if(curr_m==0&&curr_n==0)return grid[0][0];
        if(curr_m<0)return INT_MAX;
        if(curr_n<0)return INT_MAX;
        if(dp[curr_m][curr_n]!=-1)return dp[curr_m][curr_n];


        int left=INT_MAX,down=INT_MAX;
        int ansl=solveusingmemo(grid,curr_m-1,curr_n,dp);
        if(ansl!=INT_MAX)left=grid[curr_m][curr_n]+ansl;
        int ansd=solveusingmemo(grid,curr_m,curr_n-1,dp);
        if(ansd!=INT_MAX)down=grid[curr_m][curr_n]+ansd;


        dp[curr_m][curr_n]= min(left,down);
        return dp[curr_m][curr_n];
    }
    int minPathSum(vector<vector<int>>& grid) {
        // return solveusingrec(grid,grid.size()-1,grid[0].size()-1);
        vector<vector<int>>dp(grid.size()+1,vector<int>(grid[0].size()+1,-1));
        return solveusingmemo(grid,grid.size()-1,grid[0].size()-1,dp);
    }
};