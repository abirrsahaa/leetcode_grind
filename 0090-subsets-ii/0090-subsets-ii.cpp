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

// When we call helper(nums, i + 1, temp, ans);, we’re advancing the index for the recursive call to start from the next element after nums[i]. Here’s why this is important:

// Avoid Reusing the Same Element:

// By using i + 1, we’re ensuring that we only consider elements that come after nums[i] in the array for the current subset.
// If we used index + 1 instead, we would incorrectly start each recursive call from the original starting point rather than moving forward, potentially reusing elements from earlier indices.
// Generate Unique Combinations:

// This setup effectively builds each subset in a way that respects order. For example, in [1, 2, 2], starting each recursive call from i + 1 ensures that once 1 is in the subset, we only explore elements 2 and onward, never going back to previous elements.
// Handle Duplicates Properly:

// The duplicate check if (i > index && nums[i] == nums[i - 1]) continue; relies on this progression to skip over consecutive duplicates on the same recursive level.
// Using i + 1 ensures that duplicates are only considered once per combination path, leading to unique subsets.