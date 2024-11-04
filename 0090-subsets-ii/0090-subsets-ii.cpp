class Solution {
public:
    void helper(vector<int>nums,int index,vector<int>&temp,vector<vector<int>>&ans){
       
            ans.push_back(temp); //adding current subset to every level

        for(int i=index;i<nums.size();i++){
            if(i>index && nums[i]==nums[i-1])continue;
            temp.push_back(nums[i]);
            helper(nums,i+1,temp,ans);
            temp.pop_back();
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        helper(nums,0,temp,ans);
        return ans;
        
    }
};