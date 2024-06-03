class Solution {
public:
    int scoreOfString(string s) {
        int SumOfAbsDiffOfAdjChars = 0;
        for(int i = 1; i < (int)s.size(); i++) {
          int absAdjDiff = abs(s[i] - s[i - 1]);
          SumOfAbsDiffOfAdjChars += absAdjDiff;
        }
        return SumOfAbsDiffOfAdjChars;
    }
};