class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {

        // the main algo here is about 
        // to find the time of the monsters we have approahibg the base
        // and then sorting it ascendingly and see how much time we have 


        // the fact is i should also be keeping track of the time spend right 
        // like for first i shoot then for 1 min it will charge 
        if(dist.size()==1)return 1;
        
        // marne mai time nhi lagta charge hone mai time lagta hai 
        vector<double>time;
        for(int i=0;i<dist.size();i++){
            time.push_back((double)dist[i]/(double)speed[i]);
        }
        sort(time.begin(),time.end());
        int count=1;
        int timee=1;
        

        for(int i=1;i<time.size();i++){
            if(time[i]-timee>0)count++;
            else break;
            timee++;
        }
        return count;
        
    }
};