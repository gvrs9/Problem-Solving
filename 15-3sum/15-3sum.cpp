class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3) return {};
        if(nums.size() == 3) {
            if(nums[0] + nums[1] + nums[2] == 0) return {{nums[0], nums[1], nums[2]}};
            return {};
        }
        vector<vector<int> > res;
        // consider this test case if any doubt on inner while loops(not the j < k one. it is for two pointer approach). Those three individual while loops are there to skip duplicates and avoid duplicate triplets!!
        // [-4, -4, -4, -4, -1, -1, -1, -1, 0, 1, 2, 2, 2, 2, 2]
        // This question tells the power of sorting and power of Two Pointer Approach!!
        sort(nums.begin(), nums.end());
        for(int i = 0; i < (int)nums.size(); i++) {
            int j = i + 1, k = nums.size() - 1;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0) {
                    int curr_jval = nums[j], curr_kval = nums[k];
                    res.push_back({nums[i], nums[j++], nums[k--]});
                    while(j < k && nums[j] == curr_jval) j++;
                    while(j < k && nums[k] == curr_kval) k--;
                }else if(sum > 0){
                    k--;
                }else {
                    j++;
                }
            }
            while(i + 1 < (int)nums.size() && nums[i + 1] == nums[i]) i++;
        }
        return res;
    }
};