class Solution {
public:
    int appendCharacters(string s, string t) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int i = 0, j = 0;
        int sSize = s.size(), tSize = t.size();
        
        while(i < sSize && j < tSize) {
            if(s[i] == t[j]) j++;
            i++;
        }
        
        return tSize - j;
    }
};