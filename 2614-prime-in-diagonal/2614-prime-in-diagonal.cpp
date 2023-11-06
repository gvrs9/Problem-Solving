class Solution {
private:
    bool isPrime(int n) {
        if (n < 2) { // n < 2
            return false;
        } else if (n < 6) { // n < 6
            if (n == 4) return false;
            else true;
        } else { // n >= 6
            int remainder = n % 6;
            if (remainder != 1 && remainder != 5) {
                return false;
            } else { // check for divisibility by odd numbers only
                for (int i = 3; i * i <= n; i += 2) if (n % i == 0) return false;
            }
        }

        return true;
    }
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size(), m = nums[0].size();
        int maxi = 0;

        //1st diagonal and 2nd diagonal
        for (int i = 0; i < n; i++) {
            if (isPrime(nums[i][i])) maxi = max(maxi, nums[i][i]);
            if (isPrime(nums[i][n - i - 1])) maxi = max(maxi, nums[i][n - i - 1]);
        }

        return maxi;
    }
};