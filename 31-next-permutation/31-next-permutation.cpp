class Solution {
public:
    void reverse(vector<int>& nums, int low, int high) {
        while(low < high) swap(nums[low++], nums[high--]);
    }
    void nextPermutation(vector<int>& nums) {
        // [2,1,4,7,10] --> [2,1,4,10,7], [2,1,7,4,10], [2,1,7,10,4], [2,1,10,4,7], [2,1,10,7,4], [2,4,1,7,10], [2,4,1,10,7], etc.
        if(nums.size() <= 1) return;
        int breakPoint = nums.size() - 2;
        while(breakPoint >= 0 && (nums[breakPoint + 1] <= nums[breakPoint])) breakPoint--; // figuring out breakPoint
        // cout << breakPoint;
        if(breakPoint >= 0) {
            int j = nums.size() - 1;
            while(j >= 0 && nums[j] <= nums[breakPoint]) j--;
            swap(nums[breakPoint], nums[j]);
        }
        reverse(nums, breakPoint + 1, nums.size() - 1);
    }
};