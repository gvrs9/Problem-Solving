class Solution {
public:
    int maxPower(string s) {
        int maxi = 1, cnt = 1;
        for(int i = 1; s[i]; i++) {
            if(s[i] == s[i - 1]) {
                cnt++;
                maxi = max(maxi, cnt);
            }else cnt = 1;
        }
        return maxi;
    }
};