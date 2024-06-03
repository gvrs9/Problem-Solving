class Solution {
public:
    void reverseString(vector<char>& s) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int n = s.size();
        for(int i = 0; i < (n / 2); i++) swap(s[i], s[n - i - 1]);
    }
};