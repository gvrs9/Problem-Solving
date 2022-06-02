class Solution {
public:
    int maxPower(string s) {
        int maxi = 1, cnt = 1;
        char prevChar = s[0];
        for(int i = 1; s[i]; i++) {
            if(prevChar == s[i]) {
                cnt++;
                maxi = max(maxi, cnt);
                continue;
            }
            cnt = 1;
            prevChar = s[i];
        }
        return maxi;
    }
};