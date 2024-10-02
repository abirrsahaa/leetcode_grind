class Solution {
public:
    int minDeletions(string s) {
        // so the logic is to get the string sorted such that 
        // i can count the count of unique characters
        // mantain a set to keep track of count
        sort(s.begin(),s.end());
        set<int>mpp;
        int count=1;
        int deleted=0;
        for(int i=1;i<s.length();i++){
            if(s[i]!=s[i-1]){
                // check for count
                if(mpp.count(count)){
                    while(count!=0&&mpp.count(count)){
                        count--;
                        deleted++;
                    }
                    mpp.insert(count);
                    count=1;

                }else{
                    mpp.insert(count);
                    count=1;
                } 
            }else count++;
        }
         if(mpp.count(count)){
                    while(count!=0&&mpp.count(count)){
                        count--;
                        deleted++;
                    }
                }

                return deleted;
        
    }
};