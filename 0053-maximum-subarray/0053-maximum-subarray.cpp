class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /*
        // More Readable
        int sum = 0, maxi = INT_MIN;
        
        for(int i = 0; i < (int)nums.size(); i++) {
            
            sum += nums[i];
            maxi = max(maxi, sum);
            
            if(sum < 0) sum = 0;
        } */

        int maxi = INT_MIN, currSum = 0;
        for(int x : nums) {
            currSum = max(x, x + currSum);
            maxi = max(maxi, currSum);
        }
        
        return maxi;
    }
};