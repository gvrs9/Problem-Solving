class Solution {
private:
    map<char, int> romanCharsMap = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
public:
    int romanToInt(string s) {
        int n = s.size();
    
        if(n == 1) return romanCharsMap[s[0]];
        
        int numFromRoman = 0;
        
        int i = 0;
        while(i < n) {
            
            int numCurrent = romanCharsMap[s[i]];
            int numafter = romanCharsMap[s[i + 1]];
            
            if(numCurrent < numafter) {
                numFromRoman += (numafter - numCurrent);
                i += 2;
            } else {
                numFromRoman += numCurrent;
                i += 1;
            }
        }
        
        return numFromRoman;
    }
};