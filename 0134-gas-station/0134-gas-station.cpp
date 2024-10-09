class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // here i can use the brute force approach
        // of going to every index and check if it is possible from that index

        // or i can use the greedy approach of 
        // jitna kamaya hai usse zyada nahi kharcha kar sakte hai 

        // so it boils down to the fact that 
        int kamaya=accumulate(gas.begin(),gas.end(),0);
        int kharcha=accumulate(cost.begin(),cost.end(),0);
        if(kharcha>kamaya)return -1;
        else{
            // koi na koi index toh hoga 
            int total=0;
            int result=0;
            for(int i=0;i<gas.size();i++){
                if(gas[i]+total>=cost[i]){
                    total+=gas[i]-cost[i];
                }else{
                    total=0;
                    result=i+1;
                }
            }
            return result;
        }
    }
};