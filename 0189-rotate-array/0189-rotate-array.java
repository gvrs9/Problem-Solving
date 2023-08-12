class Solution {
    private static void swap(int i, int j, int[] nums) {
        nums[i] ^= nums[j];
        nums[j] ^= nums[i];
        nums[i] ^= nums[j];
    }
    private static void reverse(int i, int j, int[] nums) {
        while (i < j) swap(i++, j--, nums);
    }
    public void rotate(int[] nums, int k) {
        int n = nums.length;
        if (k == 0 || k == n) return;
        
        if(k > n) k %= n;
        
        reverse(0, n - 1, nums);
        reverse(0, k - 1, nums);
        reverse(k, n - 1, nums);
    }
}