class Solution {
public:
    int binaryGap(int n) {
        int j = -1, maxiDistance = 0;
        for (int i = 0; i < 32; i++) {
            if ((n >> i) & 1) {
                if (j != -1) maxiDistance = max(maxiDistance, i - j);
                j = i;
            }
        }
        return maxiDistance;
    }
};

/*
class Solution {
public:
    int binaryGap(int n) {
        int logNum = (int)(log2(n));
        string s = bitset<32>(n).to_string().substr(32 - (int)(log2(n)) - 1);
        int maxi = INT_MIN;
        for(int i = 0, j = 0; i < (int)s.size(); i++) if(s[i] == '1') maxi = max(maxi, i - j), j = i;
        return maxi;
    }
};
*/