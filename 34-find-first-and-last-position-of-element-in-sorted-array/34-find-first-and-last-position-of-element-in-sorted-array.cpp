class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(!nums.size()) return {-1, -1};
        if(nums.size() == 1) {
            if(nums[0] == target) {
                return {0, 0};
            }else {
                return {-1, -1};
            }
        }
        auto it1 = lower_bound(nums.begin(), nums.end(), target);
        auto it2 = upper_bound(nums.begin(), nums.end(), target);
        int start = it1 - nums.begin();
        int end = (it2 - 1) - nums.begin();
        // cout << start << " " << end << "\n";
        if(start <= nums.size() - 1 && end <= nums.size() - 1 && nums[start] == target && nums[end] == target) return {start, end};
        return {-1, -1};
    }
};