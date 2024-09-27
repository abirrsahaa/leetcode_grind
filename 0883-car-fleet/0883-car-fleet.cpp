class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        // this is a proper classical problem
        // of solving the problem 

        // and then coming to the fact that this can be solved by using a monotonic stack

        vector<pair<int,int>>mpp;
        for(int i=0;i<position.size();i++){
            mpp.push_back({position[i],speed[i]});
        }

        // here i am sorting on the basis of position 
        // such that i can make fleet based on time 

        // the whole intution here is the fact that the faster will catch the slower and then move with the speed of the slower
        sort(mpp.begin(),mpp.end());

        // now lets make a array of time
        // time =distance/speed (distance=target-position)

        vector<double>time;
        for(int i=0;i<position.size();i++){
            double dis=(double)(target-mpp[i].first);
            time.push_back(dis/(double)(mpp[i].second));
        }



        stack<double>fleet;
        for(auto i:time){
            if(fleet.empty()){
                fleet.push(i);
            }
            else{
                while(!fleet.empty()&&i>=fleet.top())fleet.pop();
                fleet.push(i);
            }
        }

        return fleet.size();
        
    }
};