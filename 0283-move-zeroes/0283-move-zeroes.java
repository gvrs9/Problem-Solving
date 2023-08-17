class Solution {
    private static void swap(int x, int y, int[] nums) {
        int temp = nums[x];
        nums[x] = nums[y];
        nums[y] = temp;
    }
    public void moveZeroes(int[] nums) {
        for(int i = 0, k = 0; i < nums.length; i++) if(nums[i] != 0) swap(k++, i, nums);
    }
}