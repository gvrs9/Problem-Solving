class Solution {
public:
    int maxPower(string s) {
        if(s.size() == 1) return 1;
        int maxi = 1, cnt = 1;
        char prevChar = s[0];
        for(int i = 1; i < (int)s.size(); i++) {
            char currChar = s[i];
            if(prevChar == currChar) {
                cnt++;
                maxi = max(maxi, cnt);
                continue;
            }
            cnt = 1;
            prevChar = currChar;
        }
        return maxi;
    }
};