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
        unordered_set<int> s;
        while(n != 1 && s.find(n) == s.end()) {
            s.insert(n);
            n = squareDigitSum(n);
            if(s.find(n) != s.end()) return false;
        }
        return true;
    }
};