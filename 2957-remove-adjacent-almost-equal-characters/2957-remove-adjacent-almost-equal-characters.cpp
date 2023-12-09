class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int ans = 0;
        
        for(int i = 1; i < (int)word.size(); i++) if(abs(word[i - 1] - word[i]) <= 1) {ans++, i++;}
        
        return ans;
    }
};