class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        
        for(const char& x: s) mp[x]++;
        
        int oddCntCharsSum =  0, oddCntChars = 0;
        int longestPalindromeLength = 0;
        
        for(const auto& [_, y] : mp) {
            if(y & 1) {
                oddCntCharsSum += y;
                oddCntChars++;
                continue;
            }
            
            longestPalindromeLength += y;
        }
        
        longestPalindromeLength += (oddCntChars ? (oddCntCharsSum - oddCntChars + 1) : 0);
        
        return longestPalindromeLength;
    }
};