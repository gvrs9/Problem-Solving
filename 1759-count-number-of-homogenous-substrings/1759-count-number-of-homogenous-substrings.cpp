const int mod = 1e9 + 7;

class Solution {
public:
    int countHomogenous(string s) {
        int res(0);
        for(long long int i = 1, j = 0; i <= (int)s.size(); i++) if(i == s.size() || s[i - 1] != s[i]) res = (res + (((i - j) * (i - j + 1)) / 2)) % mod, j = i;
        return res;
    }
};


/*

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

*/

/*

const int mod = 1e9 + 7;

class Solution {
public:
    int countHomogenous(string s) {
        int res(0), cnt(0), prev(0);
        for(int curr : s) {
            cnt = (prev == curr) ? ++cnt : 1;
            prev = curr;
            res = (res + cnt) % mod;
        }
        return res;
    }
};

*/
