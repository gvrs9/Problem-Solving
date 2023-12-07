class Solution {
public:
    int totalMoney(int n) {
        int temp = n / 7;
        int sumUntil = ((((temp * (temp - 1)) / 2) * 7) + (28 * temp));
        int diff = (n - (temp * 7));
        if(!diff) return sumUntil;
        int remaining = ((temp * 7) + ((diff * (diff + 1)) / 2) - ((7 - diff) * temp));
        return sumUntil + remaining;
    }
};