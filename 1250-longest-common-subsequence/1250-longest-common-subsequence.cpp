class Solution {
public:
    int helper(string&text1,string&text2,int pehla,int second,vector<vector<int>>&dp){
        if(pehla<0 || second<0)return 0;
        if(dp[pehla][second]!=-1)return dp[pehla][second];
        if(text1[pehla]==text2[second])return dp[pehla][second]= 1+helper(text1,text2,pehla-1,second-1,dp);
        else return dp[pehla][second]= max(helper(text1,text2,pehla-1,second,dp),helper(text1,text2,pehla,second-1,dp));
    }
    // isi ko hi tabular mai convert karna hai using state equarion 
    int tabulation (string&text1,string&text2){
        int pehla=text1.length();
        int second=text2.length();
        vector<vector<int>>dp(pehla+1,vector<int>(second+1,0));
        // base / initialization case ase socho ke 
        // how will you fill up for the first index 
        // for row wise
        for(int i=0;i<text1.size();i++){
            if(text2[0]==text1[i]){
                for(int j=i;j<text1.size();j++){
                    dp[j][0]=1;
                }
                break;
            }
        }

        for(int i=0;i<text2.length();i++){
            if(text1[0]==text2[i]){
                 for(int j=i;j<text2.size();j++){
                    dp[0][j]=1;
                }
                break;
            }
        }
        for(int i=1;i<=text1.length()-1;i++){
            for(int j=1;j<=text2.length()-1;j++){
                if(text1[i]==text2[j])dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }

        return dp[pehla-1][second-1];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int pehla=text1.length()-1;
        int second=text2.length()-1;

        vector<vector<int>>dp(text1.length()+1,vector<int>(text2.length()+1,-1));

        // return helper(text1,text2,pehla,second,dp);
        return tabulation(text1,text2);
        
    }
};