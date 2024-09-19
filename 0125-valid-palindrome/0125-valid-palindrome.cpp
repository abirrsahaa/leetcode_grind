class Solution {
public:
    bool isPalindrom(string s){
        int i=0;
        int j=s.length()-1;
        while(i<j){
            if(s[i++]!=s[j--])return false;
        }
        return true;
    }
    bool isPalindrome(string s) {

        // o(n) traversing to remove redundant 
        string ans="";
        for(auto i:s){
            int asc=i;
            if((asc>=65&&asc<=90)||(asc>=97&&asc<=122)||(asc>=48&&asc<=57))ans+=tolower(i);
        }
        cout<<ans<<endl;
        if(isPalindrom(ans))return true;
        return false;
        
    }
};