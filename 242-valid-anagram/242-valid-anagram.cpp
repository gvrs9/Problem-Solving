class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int hsh1[26] = {0};
        int hsh2[26] = {0};
        for(auto& x : s) hsh1[x - 'a']++;
        for(auto& x : t) hsh2[x - 'a']++;
        for(auto& x : t) if(hsh1[x - 'a'] != hsh2[x - 'a']) return false;
        return true;
    }
};