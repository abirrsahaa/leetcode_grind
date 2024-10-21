class Solution {
public:
    int helper(string&text1,string&text2,int pehla,int second,vector<vector<int>>&dp){
        if(pehla<0 || second<0)return 0;
        if(dp[pehla][second]!=-1)return dp[pehla][second];
        if(text1[pehla]==text2[second])return dp[pehla][second]= 1+helper(text1,text2,pehla-1,second-1,dp);
        else return dp[pehla][second]= max(helper(text1,text2,pehla-1,second,dp),helper(text1,text2,pehla,second-1,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int pehla=text1.length()-1;
        int second=text2.length()-1;

        vector<vector<int>>dp(text1.length()+1,vector<int>(text2.length()+1,-1));

        return helper(text1,text2,pehla,second,dp);
        
    }
};