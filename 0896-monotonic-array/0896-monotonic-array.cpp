class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool increasing = false, decreasing = false;
        
        for(int i = 1; i < (int)nums.size(); i++) {
            if(nums[i] < nums[i - 1]) decreasing = true;
            if(nums[i] > nums[i - 1]) increasing = true;
            if(increasing == true && decreasing == true) return false;
        }
        
        return true;
    }
};