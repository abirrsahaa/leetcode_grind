class Solution {
public:
    void reverse(string&s,int i,int j){
        while(i<j){
            swap(s[i++],s[j--]);
        }
    }
    string reverseWords(string s) {
        int i=0;
        int j=0;
        while(j<s.length()){
            while(j<s.length()&&s[j]!=' ')j++;
            reverse(s,i,j-1);
            i=j+1;j=j+1;
        }
        reverse(s,i,j-1);
        return s;
        
    }
};