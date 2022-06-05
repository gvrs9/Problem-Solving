class Solution {
public:
    int binaryGap(int n) {
        int logNum = (int)(log2(n));
        string s = bitset<64>(n).to_string().substr(64 - (int)(log2(n)) - 1);
        int maxi = INT_MIN;
        for(int i = 0, j = 0; i < (int)s.size(); i++) if(s[i] == '1') maxi = max(maxi, i - j), j = i;
        return maxi;
    }
};