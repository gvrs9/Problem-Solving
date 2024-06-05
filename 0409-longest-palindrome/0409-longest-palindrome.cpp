class Solution {
public:
    int longestPalindrome(string s) {
        /*
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
        */
        
        // Simplified the logic for calculating the palindrome length. If a character count is even, it is fully used. If a character count is odd, we use count - 1 (the largest even number less than count), and set a flag hasOdd to true. Finally, if there is any odd count, we add one to the length to include one odd character in the center of the palindrome.
        
        unordered_map<char, int> charCount;
        for (const char& c : s) {
            charCount[c]++;
        }

        int length = 0;
        bool hasOdd = false;
        for (const auto& entry : charCount) {
            if (entry.second % 2 == 0) {
                length += entry.second;
            } else {
                length += entry.second - 1;
                hasOdd = true;
            }
        }

        if (hasOdd) {
            length++; // Add one odd character to the center of the palindrome
        }

        return length;
    }
};