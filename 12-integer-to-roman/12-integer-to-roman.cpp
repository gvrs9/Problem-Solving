class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        vector<pair<string, int> > vp = {{"I", 1}, {"IV", 4}, {"V", 5}, {"IX", 9}, {"X", 10}, {"XL", 40}, {"L", 50}, {"XC", 90}, {"C", 100}, {"CD", 400}, {"D", 500}, {"CM", 900}, {"M", 1000}};
        for(auto it = vp.rbegin(); it != vp.rend(); it++) {
            if(num / it -> second) {
                int cnt = num / it -> second;
                while(cnt--) res += it -> first;
                num %= it -> second;
            }
        }
        return res;
    }
};