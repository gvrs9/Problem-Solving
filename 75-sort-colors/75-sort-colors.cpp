class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo = 0, i = 0, hi = nums.size() - 1;
        while(i <= hi) {
            if(!nums[i]) swap(nums[lo++], nums[i++]);
            else if(nums[i] == 2) swap(nums[i], nums[hi--]);
            else i++;
        }
    }
};