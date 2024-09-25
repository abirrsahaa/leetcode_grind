class Solution {
public:
    int findlength(vector<int>& nums, int target) {
        int maxi = INT_MIN;
        int i = 0, j = 0, sum = 0;

        while (j < nums.size()) {
            sum += nums[j++];
            
            while (i < nums.size() && sum >= target) {
                if (sum == target) {
                    maxi = max(maxi, j - i);  // Fix here: use j - i for length
                }
                sum -= nums[i++];
            }
            if(sum==target)return 0;
        }

        return maxi;
    }

    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum - x;

        if (target < 0) return -1;  // If x is greater than the total sum, no solution is possible

        int ans = findlength(nums, target);

        if (ans == INT_MIN) return -1;  // No valid subarray found

        return nums.size() - ans;  // Fix here: no need to add 1, just subtract ans
    }
};
