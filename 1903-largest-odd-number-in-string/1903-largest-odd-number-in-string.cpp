class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size() - 1;
        
        // if(num[n] & 1) return num;
        // num.pop_back();
        
        while(n >= 0) {
            if(num[n] & 1) return num;
            num.pop_back(), n--;
        }
        
        return num;
    }
};