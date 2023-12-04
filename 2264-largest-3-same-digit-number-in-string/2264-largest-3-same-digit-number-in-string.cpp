class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        int maxi = -1;

        for(int i = 1; i < (int)num.size() - 1; i++) {
            if((num[i - 1] == num[i] && num[i] == num[i + 1]) && ((num[i] - '0') > maxi)) {
                maxi = num[i] - '0';
            }
        }

        if(maxi > -1) {
            string temp = to_string(maxi);
            ans += temp + temp + temp;
        }

        return ans;
    }
};