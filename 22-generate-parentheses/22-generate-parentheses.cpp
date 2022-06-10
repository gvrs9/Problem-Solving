class Solution {
private:
    void helper(string& s, int openingRemainingCnt, int closingRemainingCnt) {
        if(openingRemainingCnt == 0 && closingRemainingCnt == 0) {
            validParentheses.push_back(s);
            return;
        }
        if(openingRemainingCnt > 0) s.push_back('('), helper(s, openingRemainingCnt - 1, closingRemainingCnt), s.pop_back();
        if(closingRemainingCnt > 0 && openingRemainingCnt < closingRemainingCnt) s.push_back(')'), helper(s, openingRemainingCnt, closingRemainingCnt - 1), s.pop_back();
    }
public:
    vector<string> validParentheses;
    vector<string> generateParenthesis(int n) {
        string s = "";
        helper(s, n, n);
        return validParentheses;
    }
};