class Solution {
public:
    char findTheDifference(string s, string t) {
        char ch = 0;
        // 0 ^ ch -> ch ^ 0 -> ch
        // ex: s = abc and t = bcax. Applying xor on s, a ^ b ^ c and similarly on t, b ^ c ^ a ^ x same as a ^ b ^ c ^ x. And xor both the strings s and t --> (a ^ b ^ c) ^ (a ^ b ^ c ^ x) --> (a ^ a ^ b ^ b ^ c ^ c ^ x) --> (0 ^ x) --> x.
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