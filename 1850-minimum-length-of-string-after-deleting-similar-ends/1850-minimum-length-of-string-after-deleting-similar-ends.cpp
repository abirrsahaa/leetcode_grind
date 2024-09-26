class Solution {
public:
    int minimumLength(string s) {
        int i = 0;
        int j = s.length() - 1;

        while (i < j && s[i] == s[j]) {
            // Move `i` forward while characters match
            char current_char = s[i];
            while (i <= j && s[i] == current_char) {
                i++;
            }
            // Move `j` backward while characters match
            while (i <= j && s[j] == current_char) {
                j--;
            }
        }

        return j - i + 1;
    }
};
