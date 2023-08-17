class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        if(nums.length == 1 && nums[0] == 1) return 1;
        if(nums.length == 1 && nums[0] == 0) return 0;
        int maxi = 0, temp = 0;
        if(nums[0] == 1) temp = 1;
        for (int i = 1; i < nums.length - 1; i++) {
            if(nums[i] == 1 && (nums[i - 1] == nums[i] || nums[i + 1] == nums[i])) temp++;
            else if (nums[i] == 0) {
                maxi = Math.max(maxi, temp);
                temp = 0;
            }
        }
        if(nums[nums.length - 1] == 1) temp++;
        
        maxi = Math.max(maxi, temp);
        
        return maxi;
    }
}