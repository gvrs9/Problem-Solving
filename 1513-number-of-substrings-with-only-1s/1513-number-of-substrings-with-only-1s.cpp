const int mod = 1e9 + 7;

class Solution {
public:
    int numSub(string s) {
        int res(0), cnt(0);
        for(auto& x : s) {
            if(x == '0') {
                cnt = 0;
            }else {
                cnt++;
                res = (res + cnt) % mod;
            }
        }
        return res;
    }
};

/*
        // Sliding Window!!
        int res = 0;
        for(long long int i = 0, j = 0; i <= (int)s.size(); i++) { // i <= (int)s.size() and i == s.size() because, consider this test case --> "0110111"
            if(i == s.size() || s[i] == '0')
                res = (res + (((i - j) * (i - j + 1)) / 2)) % mod, j = i + 1;
        }
        return res;

*/