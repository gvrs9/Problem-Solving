class Solution {
private:
    int squareDigitSum(int num) {
        int sum = 0;
        while(num) {
            int digit = num % 10;
            sum += digit * digit;
            num /= 10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        /*
        // O(log n) -> t.c and s.c
        unordered_set<int> s;
        while(n != 1 && s.find(n) == s.end()) {
            s.insert(n);
            n = squareDigitSum(n);
        }
        return n == 1;
        */
        
        // O(log n) -> T.C and O(1) -> S.C using slow-fast pointer method!!
        int slowRunner = n, fastRunner = squareDigitSum(n);
        while(fastRunner != 1 && slowRunner != fastRunner) {
            slowRunner = squareDigitSum(slowRunner); // once at a time
            fastRunner = squareDigitSum(squareDigitSum(fastRunner)); // twice speed
        }
        return fastRunner == 1;
    }
};