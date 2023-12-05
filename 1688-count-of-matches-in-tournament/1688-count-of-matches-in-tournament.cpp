class Solution {
public:
    int numberOfMatches(int n) {
        /* // O(log n) -> T.C
        int numberOfMatches = 0;

        while(n > 1) {
            if(n & 1) {
                numberOfMatches += ((n - 1) / 2);
                n = ((n - 1) / 2) + 1;
            } else {
                numberOfMatches += (n / 2);
                n = n / 2;
            }
        }

        return numberOfMatches; */
        
        // O(1)
        return n - 1;
    }
};