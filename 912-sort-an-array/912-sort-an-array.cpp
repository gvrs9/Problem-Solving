class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int max = *max_element(nums.begin(), nums.end());
        int min = *min_element(nums.begin(), nums.end());
        int k = max - min + 1;
        int n = nums.size();
        vector<int> count(k), output(n);
        for(int x : nums) count[x - min]++;
        for(int i = 1; i < k; i++) count[i] += count[i - 1];
        for(int i = n - 1; i >= 0; i--) {
            output[count[nums[i] - min] - 1] = nums[i];
            count[nums[i] - min]--;
        }
        return output;
    }
};