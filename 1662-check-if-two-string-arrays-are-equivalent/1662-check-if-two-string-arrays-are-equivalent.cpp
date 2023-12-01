class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        // int n1 = word1.size() - 1, n2 = word2.size() - 1;
        // int maxLength = (n1 > n2) ? n1 : n2, i = 0;
        string s1 = "", s2 = "";
        
        for(string & x : word1) s1 += x;
        for(string & x : word2) s2 += x;
        
        return s1 == s2;
    }
};