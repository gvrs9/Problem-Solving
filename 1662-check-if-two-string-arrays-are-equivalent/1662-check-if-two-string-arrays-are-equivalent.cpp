class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        // O(N*k) -> time && O(N*K) -> Space. N is the number of strings in the list and KK is the maximum length of a string in it.
        string s1 = "", s2 = "";
        
        for(string & x : word1) s1 += x;
        for(string & x : word2) s2 += x;
        
        return s1 == s2;
    }
};