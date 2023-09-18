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
/*
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int hsh_S_To_T[256] = {0};
        bool T_hsh[256] = {false};
        
        for(int i = 0; i < (int)s.size(); i++) {
            char sCurrChar = s[i], tCurrChar = t[i];
            
            if(hsh_S_To_T[sCurrChar]) {
                if(!T_hsh[tCurrChar] || hsh_S_To_T[sCurrChar] != tCurrChar) return false;
            }else {
                // cout << sCurrChar << " " << tCurrChar << "\n";
                if(T_hsh[tCurrChar]) return false;
                hsh_S_To_T[sCurrChar] = tCurrChar;
                T_hsh[tCurrChar] = true;
            }
        }
        // cout << "______________________\n";
        return true;
    }
};
*/