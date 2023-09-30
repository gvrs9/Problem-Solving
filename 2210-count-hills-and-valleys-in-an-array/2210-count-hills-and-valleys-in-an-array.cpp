class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count = 0, prev = nums[0];
        
        for(int i = 1; i < (int)nums.size() - 1; i++) {
            if((nums[i] > prev && nums[i] > nums[i + 1]) || (nums[i] < prev && nums[i] < nums[i + 1])) count++, prev = nums[i];
            // if(nums[i] != nums[i + 1]) prev = nums[i];
        }
        return count;
    }
};