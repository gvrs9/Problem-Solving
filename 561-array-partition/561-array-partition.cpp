class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int hsh[20001] = {0};
        for(int x : nums) hsh[x + 10000]++;
        int maxiSum = 0;
        bool flag = true;
        for(int i = 0; i < 20001; i++) {
            while(hsh[i]) {
                if(flag) maxiSum += i - 10000;
                flag = !flag;
                hsh[i]--;
            }
        }
        return maxiSum;
    }
};