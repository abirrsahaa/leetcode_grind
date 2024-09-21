class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // need to create a max heap
        priority_queue<int>abir;
        for(auto i:stones){
            abir.push(i);
        }

        while(abir.size()>1){
            int y=abir.top();
            abir.pop();
            int x=abir.top();
            abir.pop();
            if(y!=x)abir.push(y-x);
        }
        if(!abir.size())return 0;
        return abir.top();
        
    }
};