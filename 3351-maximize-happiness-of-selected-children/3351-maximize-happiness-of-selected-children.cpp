class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end());
        int count=0;
        int i=happiness.size()-1;
        long long sum=0;
        while(k--&&i>=0){
            if(happiness[i]-count>0){
                sum+=happiness[i]-count;
                count++;
            }
            i--;
        }
        return sum;
        
    }
};