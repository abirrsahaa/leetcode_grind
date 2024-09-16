class Solution {
public:

    bool isValid(int mid,int target,vector<int>&nums){
        int count=1;
        int curr=0;

        // main thing here is to count in a proper way
        for(int i=0;i<nums.size();i++){
            curr+=nums[i];
            if(curr>mid){
                count++;
                curr=nums[i];
            }
        }
        // if(curr<=mid)count++;
        return count<=target;

    }
    int splitArray(vector<int>& nums, int k) {

        int start=*max_element(nums.begin(),nums.end());
        int end=accumulate(nums.begin(),nums.end(),0);

        int ans=end;

        while(start<=end){
            int mid=(end-start)/2+start;

            if(isValid(mid,k,nums)){
                ans=mid;
                end=mid-1;
            }
            else start=mid+1;
        }

        return ans;
        
    }
};