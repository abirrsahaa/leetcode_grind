class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {

        // the intuition is 
        // i will keep a track of the frequency of all the distict elements 
        // and the fact is as i need the least number of unique elements
        // i should be eliminatinf rhe integers with least frequency until k allows 
        
        // so one approach would be to use map and then 
        // either use a vector of pair which will be sorted according to freq
        // and will be removing until k allows 
        // or use heap although i think heap will take nlogn also for insertion so there wont be any difference
        unordered_map<int,int>abir;
        for(auto i:arr){
            abir[i]++;
        }
        vector<int>freq;
        for(auto i=abir.begin();i!=abir.end();i++){
            freq.push_back(i->second);
        }
        sort(freq.begin(),freq.end());
        int i=0;
        while(i<freq.size()&&k>=freq[i]){
            k-=freq[i];
            i++;
        }
        return freq.size()-i;
        
    }
};