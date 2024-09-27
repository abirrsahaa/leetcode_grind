class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();

        // Next smaller element array initialized to n (out of bounds)
        vector<int> nse(n, n);
        // Previous smaller element array initialized to -1
        vector<int> pse(n, -1);

        // Find next smaller elements using a monotonic stack
        stack<int> mpp;
        for (int i = n - 1; i >= 0; i--) {
            while (!mpp.empty() && heights[mpp.top()] >= heights[i]) {
                mpp.pop();
            }
            if (!mpp.empty()) nse[i] = mpp.top();
            mpp.push(i);  // Push the index, not the value
        }

        // Find previous smaller elements using another stack
        stack<int> mppp;
        for (int i = 0; i < n; i++) {
            while (!mppp.empty() && heights[mppp.top()] >= heights[i]) {
                mppp.pop();
            }
            if (!mppp.empty()) pse[i] = mppp.top();
            mppp.push(i);  // Push the index, not the value
        }

        // Calculate the maximum area
        int max_area = 0;
        for (int i = 0; i < n; i++) {
            int width = nse[i] - pse[i] - 1;  // Calculate the width
            int area = width * heights[i];    // Area with heights[i] as the smallest bar
            max_area = max(max_area, area);
        }

        return max_area;
    }
};
