class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {

        // here is also a greedy approach 
        // greedy is nothing but playing a game more smartly 
        // such that here i have a option to loose one point and gain power 
        // so it is better for me to gain a bigger power than a smaller power

        if(tokens.size()==0)return 0;

        int score=0;
        int i=0;
        sort(tokens.begin(),tokens.end());
        int j=tokens.size()-1;
        if(power<tokens[0])return 0;
        int maxi=INT_MIN;

        while(i<=j){
            if(power>=tokens[i]){
                power-=tokens[i++];
                score++;
                maxi=max(score,maxi);
            }
            else{
                power+=tokens[j--];
                score--;
            }
        }
        return maxi;
        
    }
};