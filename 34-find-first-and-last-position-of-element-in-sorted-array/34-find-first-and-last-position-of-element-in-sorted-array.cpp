class Solution {
private:
    int findFirst(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        int res = -1;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] < target) {
                lo = mid + 1;
            }else if(nums[mid] > target) {
                hi = mid - 1;
            }else {
                res = mid;
                hi = mid - 1;
            }
        }
        return res;
    }
    int findLast(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        int res = -1;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] < target) {
                lo = mid + 1;
            }else if(nums[mid] > target) {
                hi = mid - 1;
            }else {
                res = mid;
                lo = mid + 1;
            }
        }
        return res;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {findFirst(nums, target), findLast(nums, target)};
    }
};