class Solution {
public:
    string breakPalindrome(string palindrome) {
        // the main algo here is to make it lexographically small
        // and the fact that need to traverse only to half 
        if(palindrome.length()==1)return "";

        for(int i=0;i<palindrome.length()/2;i++){
            if(palindrome[i]!='a'){
                palindrome[i]='a';
                return palindrome;
            }
        }
        palindrome[palindrome.length()-1]='b';
        return palindrome;
        
    }
};