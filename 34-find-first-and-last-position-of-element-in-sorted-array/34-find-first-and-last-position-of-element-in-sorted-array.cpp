class Solution {
private:
    int binarySearch(vector<int>& nums, int target, bool flag) {
        int lo = 0, hi = nums.size() - 1;
        int res = -1;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] < target) {
                lo = mid + 1;
            }else if(nums[mid] > target){
                hi = mid - 1;
            }else {
                res = mid;
                if(flag) {
                    hi = mid - 1;
                }else {
                    lo = mid + 1;
                }
            }
        }
        return res;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {binarySearch(nums, target, true), binarySearch(nums, target, false)};
    }
};