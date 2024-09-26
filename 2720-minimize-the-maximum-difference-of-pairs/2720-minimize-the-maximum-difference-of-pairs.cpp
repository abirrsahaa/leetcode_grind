class Solution {
public:

    bool isValid(vector<int>&nums,int mid,int p){
        int count=0;

        int i=0;
        while(i<nums.size()-1){
            if(nums[i+1]-nums[i]<=mid){
                count++;
                i+=2;
            }
            else i++;
        }

        return count>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {

        // although i was good with finding the intuition of it 
        // this is simply a variation of binary search on answers 

        sort(nums.begin(),nums.end());
        int start=0;
        int end=nums[nums.size()-1]-nums[0];

        int ans=-1;

        while(start<=end){
            int mid=start+(end-start)/2;

            if(isValid(nums,mid,p)){
                ans=mid;
                end=mid-1;
            }
            else start=mid+1;
        }

        return ans;
        
    }
};