class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {

        // the pattern which i have realised is that 
        // if i can get the more growing time earlier 
        // then i can work on more plants thus speeding up the process
        // so lets make an array of pair and then sort it with respect to the first
        // in terms descending order

        vector<pair<int,int>>abir;
        for(int i=0;i<growTime.size();i++){
            abir.push_back({growTime[i],plantTime[i]});
        }
        sort(abir.begin(),abir.end());
        // traverse from backwards as usse pehle milega bada wala
        int curr=0;
        int next=0;
        int bloom=0;
        for(int i=abir.size()-1;i>=0;i--){
            next=curr+abir[i].second;
            bloom=max(bloom,next+abir[i].first);
            curr=next;
        }
        return bloom;
    }
};