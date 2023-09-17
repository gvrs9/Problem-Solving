class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int hsh_Map_S_To_T[256] = {0}, hsh_Map_T_To_S[256] = {0};
        
        for(int i = 0; i < (int)s.size(); i++) {
            if((hsh_Map_S_To_T[s[i]] && hsh_Map_S_To_T[s[i]] != t[i]) || (hsh_Map_T_To_S[t[i]] && hsh_Map_T_To_S[t[i]] != s[i])) return false;
            hsh_Map_S_To_T[s[i]] = t[i];
            hsh_Map_T_To_S[t[i]] = s[i];
        }
        
        return true;
    }
};