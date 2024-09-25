// this needs care and attention 

// Code Walkthrough
// cpp
// Copy code
// for(int i = 0; i < s.size(); i++) {
//     if(s1[i] != s[i]) ++ans1;
//     if(s2[i] != s[i]) ++ans2;
//     if(i >= n) { 
//         if(s1[i - n] != s[i - n]) --ans1;
//         if(s2[i - n] != s[i - n]) --ans2;
//     }
//     if(i >= n - 1)
//         ans = min({ans1, ans2, ans});
// }
// return ans;
// 1. Comparing Characters of s and Alternating Strings (s1 and s2)
// cpp
// Copy code
// if(s1[i] != s[i]) ++ans1;
// if(s2[i] != s[i]) ++ans2;
// Here, s1 and s2 are two possible alternating patterns:

// s1 starts with '1', and alternates: 101010...
// s2 starts with '0', and alternates: 010101...
// For each character in the doubled string s, this checks:

// If the character at index i in s1 doesn't match the character in s, increment ans1 (indicating a flip is needed to match s1).
// Similarly, check if the character in s2 doesn't match the character in s, and increment ans2 (indicating a flip is needed to match s2).
// 2. Sliding Window and Subtracting Extra Flips
// cpp
// Copy code
// if(i >= n) { 
//     if(s1[i - n] != s[i - n]) --ans1;
//     if(s2[i - n] != s[i - n]) --ans2;
// }
// This part handles the sliding window mechanism:

// The window size n is the length of the original string.
// When i >= n, the leftmost element of the window (at position i - n) is no longer part of the current window. So, if that character was considered a mismatch earlier and caused a flip (tracked in ans1 or ans2), we now undo that flip by decrementing ans1 or ans2 accordingly.
// This ensures that the sliding window is always correctly counting the flips for the current substring of length n.

// 3. Tracking the Minimum Number of Flips
// cpp
// Copy code
// if(i >= n - 1)
//     ans = min({ans1, ans2, ans});
// Once the window reaches a valid size (i.e., i >= n - 1), the code calculates the minimum flips required (ans) between the two alternating patterns s1 and s2.

// ans1 tracks flips to make the substring match s1.
// ans2 tracks flips to make the substring match s2.
// The minimum of these two, along with the current minimum ans, is stored to track the overall minimum flips required.

// Key Insight
// The core of the solution is to:

// Simulate a circular shift using a sliding window over the doubled string.
// Track mismatches with the two possible alternating patterns (s1 and s2).
// Adjust the count of flips dynamically as the window moves by subtracting the flips for characters that exit the window.
// This approach efficiently finds the minimum number of flips needed to make the binary string alternating after any possible circular shift.



class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        s += s;
        string s1, s2;
        
        for(int i = 0; i < s.size(); i++) {
            s1 += i % 2 ? '0' : '1';
            s2 += i % 2 ? '1' : '0';
        }
        int ans1 = 0, ans2 = 0, ans = INT_MAX;
        for(int i = 0; i < s.size(); i++) {
            if(s1[i] != s[i]) ++ans1;
            if(s2[i] != s[i]) ++ans2;
            if(i >= n) { //the most left element is outside of sliding window, we need to subtract the ans if we did `flip` before.
                if(s1[i - n] != s[i - n]) --ans1;
                if(s2[i - n] != s[i - n]) --ans2;
            }
            if(i >= n - 1)
                ans = min({ans1, ans2, ans});
        }
        return ans;
    }
};