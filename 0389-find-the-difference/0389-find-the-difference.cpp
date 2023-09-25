class Solution {
public:
    char findTheDifference(string s, string t) {
        char ch = 0;
        
        for(char x : s) ch ^= x;
        for(char x : t) ch ^= x;
        
        return ch;
    }
};


/*
class Solution {
public:
    char findTheDifference(string s, string t) {
        int i = 0, sSum = 0, tSum = 0;
        
        while(i < (int)s.size()) sSum += s[i], tSum += t[i++];
        
        tSum += t[i];
        
        return char(tSum - sSum); // don't need to explicitly convert it.
    }
};
*/