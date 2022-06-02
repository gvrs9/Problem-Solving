const int mod = 1e9 + 7;

class Solution {
public:
    int countHomogenous(string s) {
        int res(0), cnt(0);
        char prevChar = s[0];
        for(auto& currChar : s) {
            cnt = (prevChar == currChar) ? ++cnt : 1;
            prevChar = currChar;
            res = (res + cnt) % mod;
        }
        return res;
    }
};