class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int hsh[20001] = {0};
        for(int i = 0; i < (int)nums.size(); i++) hsh[nums[i] + 10000]++;
        int maxi = 0;
        bool flag = true;
        for(int i = 0; i < 20001; i++) {
            while(hsh[i]) {
                if(flag) maxi += i - 10000;
                flag = !flag;
                hsh[i]--;
            }
        }
        return maxi;
    }
};