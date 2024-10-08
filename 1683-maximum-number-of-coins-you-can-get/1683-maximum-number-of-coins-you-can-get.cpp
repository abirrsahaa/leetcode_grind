class Solution {
public:
    int maxCoins(vector<int>& piles) {
        // the intuition here is greedy 
        // we know the fact that the third person will always get the least out of the 3
        // so why not i give him the least hence making some room to increase my greedy
        // as because comparison to give 3 greedily from the back now i am giving only two 
        // hence making me much more richer 

        sort(piles.begin(),piles.end());

        int sum=0;

        int x=piles.size()/3;
        for(int i=piles.size()-2;i>=x-1;i-=2){
            sum+=piles[i];
        }

        return sum;

    }
};