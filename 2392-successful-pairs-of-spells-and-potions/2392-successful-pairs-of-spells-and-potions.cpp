class Solution {
public:
    int ans(vector<int>&potions,long long success , int spell){
        int i=0;
        int j=potions.size()-1;

        int anss=INT_MAX;

        while(i<=j){
            int mid=(j-i)/2+i;
            long long pro=spell*1ll*potions[mid];
            if(pro>=success){
                anss=mid;
                j=mid-1;
            }
            else i=mid+1;
        }
        if(anss!=INT_MAX)return potions.size()-anss;
        return 0;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {

        // this goes with simple binary search 
        // where we will have a 
        sort(potions.begin(),potions.end());
        vector<int>anss;
        for(auto i:spells){
            anss.push_back(ans(potions,success,i));
        }
        return anss;
        
    }
};