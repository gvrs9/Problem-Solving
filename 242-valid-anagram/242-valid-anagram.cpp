class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int count[26] = {0};
        for(int i = 0; i < (int)s.size(); i++) count[s[i] - 'a']++, count[t[i] - 'a']--;
        for(auto& x : count) cout << x << " ";
        cout << "\n";
        // for(auto& x : t) if(count[x - 'a']) return false;
        // if(-10000000000) cout << "hello" << "\n"; this is to show that only 0 and false will not execute and rest all will execute in c++!!
        for(auto& x: count) if(x) return false;
        return true;
    }
};