class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3) return {};
        if(nums.size() == 3) {
            if(nums[0] + nums[1] + nums[2] == 0) return {{nums[0], nums[1], nums[2]}};
            return {};
        }
        vector<vector<int> > res;
        
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