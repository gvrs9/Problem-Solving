class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        // int closest = nums[0] + nums[1] + nums[2];
        // or 
        long long closest = INT_MAX;
        for(int i = 0; i < (int)nums.size() - 2; i++) {
            int j = i + 1, k = nums.size() - 1;
            while(j < k) {
                int currSum = nums[i] + nums[j] + nums[k];
                if(currSum == target) return currSum;
                if(abs(target - currSum) < abs(target - closest)) closest = currSum;
                if(currSum < target) j++;
                else k--;
            }
            while(i + 1 < nums.size() && nums[i + 1] == nums[i]) i++;
        }
        return closest;
    }
};