class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {

        int time=0;
        stack<pair<char,int>>abir;
        for(int i=0;i<colors.length();i++){
            if(abir.empty())abir.push({colors[i],i});
            else{
                auto pehla=abir.top();
                char element=pehla.first;
                int index=pehla.second;
                if(colors[i]!=element)abir.push({colors[i],i});
                else{
                    // 2 cases either mera wala zyada time kheyga 
                    if(neededTime[index]>neededTime[i]){
                        time+=neededTime[i];
                    }else{
                        abir.pop();
                        time+=neededTime[index];
                        abir.push({colors[i],i});
                    }
                    // ya fir jo naya hai woh 
                }

            }
        }
        return time;
        
    }
};