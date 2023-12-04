class Solution {
public:
    string largestOddNumber(string num) {
        string maxOddNumber = "";
        string temp = "";
        
        for(int i = 0; i < (int)num.size(); i++) {
            temp.push_back(num[i]);
            if(((temp.back() - '0') & 1)) maxOddNumber = temp;
        }
        
        return maxOddNumber;
    }
};