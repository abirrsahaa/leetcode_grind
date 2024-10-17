class Solution {
public:

    int helper(vector<vector<int>>&triangle,int n,int index,vector<vector<int>>&dp){
        if(n==triangle.size())return 0;
        if(dp[n][index]!=-1)return dp[n][index];

        int ans=INT_MAX;
        int pehla=triangle[n][index];
        ans=min(ans,helper(triangle,n+1,index,dp)+pehla);
        int dusra=INT_MAX;
        if(index+1<triangle[n].size()){
            dusra=triangle[n][index+1];
            ans=min(ans,helper(triangle,n+1,index+1,dp)+dusra);
        }

        

        return dp[n][index]= ans;
        

    }

    int minimumTotal(vector<vector<int>>& triangle) {

    vector<vector<int>>dp(triangle.size()+1,vector<int>(triangle[triangle.size()-1].size()+1,-1));

    return helper(triangle,0,0,dp);
        
    }
};