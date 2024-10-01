class Solution {
public:
    int partitionString(string s) {
        int count=1;
        int i=1;
        
        unordered_set<char>mpp;
        mpp.insert(s[0]);
        while(i<s.length()){
            
            if(mpp.count(s[i])){
                count++;
                mpp.clear();
                mpp.insert(s[i]);
            }
            else mpp.insert(s[i]);

            i++;

        }
        
        return count;
    }
};