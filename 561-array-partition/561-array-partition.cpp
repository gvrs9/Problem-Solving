class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int hsh[20001] = {0};
        for(int x : nums) hsh[x + 10000]++;
        int maxiSum = 0;
        bool odd = true;
        for(int i = 0; i < 20001; i++) {
            while(hsh[i]) {
                if(odd) maxiSum += i - 10000;
                odd = !odd;
                hsh[i]--;
            }
        }
        return maxiSum;
    }
};