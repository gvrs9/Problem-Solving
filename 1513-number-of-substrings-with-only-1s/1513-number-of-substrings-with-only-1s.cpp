const int mod = 1e9 + 7;

class Solution {
public:
    int numSub(string s) {
        int res = 0;
        for(long long int i = 0, j = 0; i <= (int)s.size(); i++) {
            if(i == s.size() || s[i] == '0')
                res = (res + (((i - j) * (i - j + 1)) / 2)) % mod, j = i + 1;
        }
        return res;
    }
};