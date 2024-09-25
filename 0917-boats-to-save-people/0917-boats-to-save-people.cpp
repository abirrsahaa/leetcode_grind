class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {

        // this is a classical problem of greedy 
        // here the main intution is thw fact that 
        // i should let the higher weight wala persons to go first 
        // such that bad mai patle walo ko ak khatte bhej pau
        // ab do bhari nahi ayega justified hai toh agar bhari ke sath ak patla aa jaye toh kyu na 


        // is algo isliye bhi hai kyu ki humko bss bola hai ke only 2 ja sakte hai
        int count=0;
        sort(people.begin(),people.end());
        int i=0;
        int j=people.size()-1;
        while(i<=j){
            if(people[j]+people[i]<=limit){
                i++;
                
            }
            j--;
            count++;
        }
        return count;
        
    }
};