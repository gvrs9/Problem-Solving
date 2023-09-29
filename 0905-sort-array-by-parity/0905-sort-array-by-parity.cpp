class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0, right = 0;
        
        while(right < (int)nums.size()) {
            if(nums[right] % 2 == 0 && nums[left] % 2) swap(nums[right], nums[left++]);
            else if(nums[left] % 2 == 0 && nums[right] % 2) left++;
            else if(nums[left] % 2 == 0 && nums[right] % 2 == 0) left++;
            right++;
        }
        
        return nums;
    }
};