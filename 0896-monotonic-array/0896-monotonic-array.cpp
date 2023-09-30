class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool increasing = false, decreasing = false;
        
        for(int i = 1; i < (int)nums.size(); i++) {
            if(increasing && decreasing) return false;
            if(nums[i] < nums[i - 1]) decreasing = true;
            if(nums[i] > nums[i - 1]) increasing = true;
        }
        
        return (increasing && decreasing) ? false : true;
    }
};