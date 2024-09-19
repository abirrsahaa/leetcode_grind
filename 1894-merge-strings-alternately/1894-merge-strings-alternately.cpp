class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0;
        int j=0;
        string ans="";
        while(i<word1.length()&&j<word2.length()){
            ans+=word1[i++];
            ans+=word2[j++];
        }
        if(i<word1.length()){
            while(i<word1.length())ans+=word1[i++];
        }
        if(j<word2.length()){
            while(j<word2.length())ans+=word2[j++];
        }
        return ans;
        
    }
};