class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int wordStartIndex = 0;
        // string ansString = '';
        
        for(int i = 0; i <= n; i++) {
            if(s[i] == ' ' || i == n) {
                int mid = (wordStartIndex + (i)) / 2; // 
                // cout << wordStartIndex << " " << (i - 1) << " " << mid << "\n";
                for(int j = wordStartIndex; j < (wordStartIndex + (i)) / 2; j++) 
                    swap(s[j], s[(i - j - 1) + wordStartIndex]);
                // cout << s << "\n";
                wordStartIndex = i + 1;
            }
        }
        
        return s;
    }
};