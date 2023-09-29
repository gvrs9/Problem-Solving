class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0, right = 0;
        
        while(right < (int)nums.size()) {
            if(!(nums[right] & 1)) swap(nums[left++], nums[right]);
            right++;
        }
        
        return nums;
    }
};