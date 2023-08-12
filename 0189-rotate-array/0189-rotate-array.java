class Solution {
    private static void swap(int i, int j, int[] nums) {
        int x = nums[i], y = nums[j];
        x = x ^ y;
        y = x ^ y;
        x = x ^ y;
        nums[i] = x;
        nums[j] = y;
    }
    private static void reverse(int i, int j, int[] nums) {
        while (i < j) swap(i++, j--, nums);
    }
    public void rotate(int[] nums, int k) {
        int n = nums.length;
        if (k == 0 || k == n) return;
        
        k %= n;
        
        reverse(0, n - 1, nums);
        reverse(0, k - 1, nums);
        reverse(k, n - 1, nums);
    }
}