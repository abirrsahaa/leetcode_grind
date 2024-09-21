class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        if(colors.length()==1)return 0; //as there are no consecutive color so no need to remove 
        int prev=0;
        int curr=1;
        int time=0;
        while(curr<colors.length()){
            if(colors[prev]!=colors[curr]){
                prev=curr;
                curr++;
            }
            else{
                if(neededTime[prev]<neededTime[curr]){
                    time+=neededTime[prev];
                    prev=curr;
                    curr++;
                }
                else{
                    time+=neededTime[curr];
                    curr++;
                }
            }
        }
        return time;

        
    }
};