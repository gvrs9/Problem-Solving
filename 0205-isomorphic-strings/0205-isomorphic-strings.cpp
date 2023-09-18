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
                cout << sCurrChar << " " << tCurrChar << "\n";
                if(T_hsh[tCurrChar]) return false;
                hsh_S_To_T[sCurrChar] = tCurrChar;
                T_hsh[tCurrChar] = true;
            }
        }
        cout << "______________________\n";
        return true;
    }
};