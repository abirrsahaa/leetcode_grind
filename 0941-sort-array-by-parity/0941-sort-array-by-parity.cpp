class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        // similar as o and 1 bunary consition ko hamesga 0&1 se socho 

        int last=-1;
        int valid=0;
        while(valid<nums.size()){
            // cout<<"in this iteration "<<endl;
            // cout<<last<<" "<<valid<<endl;
            while(valid<nums.size()&&(nums[valid]&1))valid++;
            if(last+1<nums.size()&&valid<nums.size())swap(nums[valid],nums[last+1]);
            last=last+1;
            valid++;
        }
        return nums;
        
    }
};