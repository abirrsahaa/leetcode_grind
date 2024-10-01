class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        for(int i=0;i<rocks.size();i++){
            rocks[i]=capacity[i]-rocks[i];
        }
        int count=0;
        sort(rocks.begin(),rocks.end());
        for(int i=0;i<rocks.size();i++){
            if(additionalRocks>=rocks[i]){
                count++;
                additionalRocks-=rocks[i];
            }
            else break;
        }
        return count;
        
    }
};