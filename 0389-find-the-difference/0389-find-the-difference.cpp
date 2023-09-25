class Solution {
public:
    char findTheDifference(string s, string t) {
        int i = 0, sSum = 0, tSum = 0;
        while(i < (int)s.size()) sSum += (s[i] - 'a'), tSum += (t[i++] - 'a');
        tSum += (t[i] - 'a');
        
        return char((tSum - sSum) + 97);
    }
};