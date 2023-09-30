class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        bool up = (nums[n - 1] - nums[0]) > 0;

        for(int i = 1; i < n; i++) {
            if(nums[i] != nums[i - 1] && ((nums[i] - nums[i - 1]) > 0) != up) return false;
        }

        return true;
    }
};


/*
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        // if(nums.size() == 1) return true;
        
        int n = nums.size();
        bool up = (nums[0] < nums[n - 1]) > 0;

        for(int i = 1; i < n; i++) {
            if(nums[i] != nums[i - 1] && (nums[i - 1] < nums[i]) != up) return false;
        }

        return true;
    }
};
*/


/*
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
*/