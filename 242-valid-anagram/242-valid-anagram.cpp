class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int count[26] = {0};
        for(int i = 0; i < (int)s.size(); i++) count[s[i] - 'a']++, count[t[i] - 'a']--;
        for(auto& x : t) if(count[x - 'a']) return false;
        return true;
    }
};