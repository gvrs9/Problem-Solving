class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0, j = 0;
        int sSize = s.size(), tSize = t.size();
        
        while(i < sSize && j < tSize) {
            if(s[i] == t[j]) j++;
            i++;
        }
        
        return tSize - j;
    }
};