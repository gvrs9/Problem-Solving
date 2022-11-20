class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mapi;
        mapi['I'] = 1, mapi['V'] = 5, mapi['X'] = 10, mapi['L'] = 50, mapi['C'] = 100, mapi['D'] = 500, mapi['M'] = 1000;
        if(s.size() == 1) return mapi[s[0]];
        int ans = mapi[s[0]], i = 1;
        while(i < (int)s.size()) {
            if(mapi[s[i]] > mapi[s[i - 1]]) {
                // cout << s[i - 1] << " " << s[i] << "\n";
                // cout << "hey\n";
                ans -= mapi[s[i - 1]];
                ans += mapi[s[i]] - mapi[s[i - 1]];
            }
            else ans += mapi[s[i]];
            i++;
        }
        return ans;
    }
};