class Solution {
public:
void solve(int idx, vector<int>& nums, vector<vector<int>>& ans, vector<int>& res, int k) {
    if (res.size() == k) {  // Base case: If res has k elements, it's a valid combination.
        ans.push_back(res);  // Add res to the list of results.
        return;
    }

        for (int i = idx; i < nums.size(); i++) {
        res.push_back(nums[i]);  // Choose the current element.
        solve(i + 1, nums, ans, res, k);  // Recurse with the next index.
        res.pop_back();  // Backtrack by removing the last added element.
    }
}


    vector<vector<int>> combine(int n, int k) {
          vector<int> res;  // Temporary vector to store each combination.
    vector<vector<int>> ans;  // Result vector to store all combinations.
    vector<int> nums;  // List of numbers from 1 to n.
    for (int i = 1; i <= n; i++) {
        nums.push_back(i);  // Fill nums with values from 1 to n.
    }

    solve(0, nums, ans, res, k);  // Start recursive backtracking from index 0.
    return ans;
    }
};