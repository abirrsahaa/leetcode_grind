class Solution {
public:
    void helper(vector<int>& temp, vector<vector<int>>& ans, int index, int k, int n) {
        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        }
        if(temp.size()>k)return;
        for (int i = index; i <= n; i++) {
            temp.push_back(i);          // Include element `i`
            helper(temp, ans, i + 1, k, n); // Move to next index
            temp.pop_back();             // Backtrack
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>> ans;
        helper(temp, ans, 1, k, n);
        return ans;
    }
};
