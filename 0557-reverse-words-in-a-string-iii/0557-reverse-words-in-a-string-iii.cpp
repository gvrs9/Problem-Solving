auto init = []()
{
    ios::sync_with_stdio(false);  // Disable synchronization between C and C++ standard streams for performance
    cin.tie(nullptr);             // Unlink cin from cout for performance reasons.
    cout.tie(nullptr);            // Unlink cout from cin for performance reasons.
    return 'c';                   // Return the character 'c'.
}();

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int wordStartIndex = 0;
        
        for(int i = 0; i <= n; i++) {
            if(s[i] == ' ' || i == n) {
                int mid = (wordStartIndex + (i)) / 2;
                
                for(int j = wordStartIndex; j < mid; j++) 
                    swap(s[j], s[(i - j - 1) + wordStartIndex]);
                
                wordStartIndex = i + 1;
            }
        }
        
        return s;
    }
};