/*
https://leetcode.com/problems/longest-substring-without-repeating-characters
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int freq[256] = {0};
        int left = 0;
        int right = -1;
        int result = 0;
        
        while (left < s.length()) {
            if (right + 1 < s.length() && freq[s[right + 1]] == 0) {
                right++;
                freq[s[right]]++;
            } else {
                freq[s[left]]--;
                left++;
            }
            result  = max(result, right - left + 1);
        }
        return result;
    }
};