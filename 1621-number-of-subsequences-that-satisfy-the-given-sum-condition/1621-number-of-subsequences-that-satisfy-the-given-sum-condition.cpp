class Solution {
public:
    const int MOD = 1e9 + 7;

    int numSubseq(vector<int>& nums, int target) {
        // Sort the array to apply the two-pointer approach
        sort(nums.begin(), nums.end());

        // Precompute powers of 2 up to the length of nums
        vector<int> power(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            power[i] = (power[i - 1] * 2) % MOD;
        }

        int count = 0;
        int i = 0, j = nums.size() - 1;

        while (i <= j) {
            // If the sum of the smallest and largest element is too large, move the right pointer
            if (nums[i] + nums[j] > target) {
                j--;
            } else {
                // Otherwise, count all subsequences formed by nums[i] and any combination of elements between i and j
                count = (count + power[j - i]) % MOD;
                i++;
            }
        }

        return count;
    }
};
