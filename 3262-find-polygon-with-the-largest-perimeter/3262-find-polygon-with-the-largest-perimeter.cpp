class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {

        // the intuition came from the problem statement only 
        // here i am using prefix sum and traversing from backwards 
        // as there wont be negative elements 
        // so the more the size of the polygon the maximum is the answer 
   

        sort(nums.begin(),nums.end());
        vector<long long>pre(nums.size());
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            pre[i]=sum;
        }
        for(int i=pre.size()-1;i>=2;i--){
            if(pre[i-1]>nums[i])return pre[i];
        }
        return -1;
        
    }
};