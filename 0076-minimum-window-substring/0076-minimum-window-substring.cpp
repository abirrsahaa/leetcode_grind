class Solution {
public:
    string minWindow(string s, string t) {
        if (t.length() > s.length()) return "";

        unordered_map<char, int> mpp;
        for (auto c : t) {
            mpp[c]++;
        }

        int count = t.length();  // Total number of characters to match
        int min_len = INT_MAX;   // Minimum window size
        int start_index = 0;     // Start index of the minimum window
        int i = 0, j = 0;

        while (j < s.length()) {
            // If character is needed in t and its count is positive, reduce the count
            if (mpp[s[j]] > 0) {
                count--;
            }

            // Decrease the count of the character in the map
            mpp[s[j]]--;

            // Once we've found a valid window, start shrinking from the left
            while (count == 0) {
                if (j - i + 1 < min_len) {
                    min_len = j - i + 1;
                    start_index = i;
                }

                // Shrink the window from the left
                mpp[s[i]]++;

                // If the character at `i` was part of t, we need to increase the count
                if (mpp[s[i]] > 0) {
                    count++;
                }

                i++;
            }

            j++;
        }

        // If no valid window was found
        if (min_len == INT_MAX) return "";

        return s.substr(start_index, min_len);
    }
};
