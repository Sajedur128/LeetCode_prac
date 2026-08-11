class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last_seen(128, -1); // Tracks the last index where each character appeared
        int max_len = 0;
        int left = 0; // Left boundary of the sliding window

        for (int right = 0; right < s.length(); ++right) {
            char current = s[right];
            
            // If the character was seen inside the current window, move the left pointer
            if (last_seen[current] >= left) {
                left = last_seen[current] + 1;
            }

            // Update the last seen position of the current character
            last_seen[current] = right;

            // Calculate the max length of the valid substring
            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};