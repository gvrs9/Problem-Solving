class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        /* 
        // O(N*k) -> time && O(N*K) -> Space. N is the number of strings in the list and KK is the maximum length of a string in it.
        string s1 = "", s2 = "";
        
        for(const string & x : word1) s1 += x;
        for(const string & x : word2) s2 += x;
        
        return s1 == s2; */

        // O(N * K) -> time and O(1) -> space using pointers method

        int i = 0, j = 0; // wordCounters
        int charOfStringOfWord1 = 0, charOfStringOfWord2 = 0;
        while(i < word1.size() && j < word2.size()) {
            if(word1[i][charOfStringOfWord1++] != word2[j][charOfStringOfWord2++]) return false;

            if(charOfStringOfWord1 == word1[i].size()) {
                charOfStringOfWord1 = 0;
                i++;
            }

            if(charOfStringOfWord2 == word2[j].size()) {
                charOfStringOfWord2 = 0;
                j++;
            }
        }

        return (i == word1.size() && j == word2.size());
    }
};