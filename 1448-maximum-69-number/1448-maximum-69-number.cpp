class Solution {
public:
    int maximum69Number (int num) {
        string abir=to_string(num);
        for(int i=0;i<abir.length();i++){
            if(abir[i]=='6'){
                abir[i]='9';
                break;
            }
        }
        return stoi(abir);
        
    }
};