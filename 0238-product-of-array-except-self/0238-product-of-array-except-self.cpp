class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // prefix sum using prefix array and suffix(or postfix) array
        // O(n) -> T.C & S.C
        
        vector<int> ans(nums.size()), pref(nums.size() + 1), suff(nums.size() + 1);
        
        pref[0] = 1;
        suff[nums.size()] = 1;
        
        for(int i = 1; i < (int)pref.size(); i++) pref[i] = pref[i - 1] * nums[i - 1];
        
        // for(int x : pref) cout << x << " ";
        // cout << "\n";
        
        for(int i = suff.size() - 2; i >= 0; i--) suff[i] = suff[i + 1] * nums[i];
        
        // for(auto x : suff) cout << x << " ";
        // cout << "\n";
        
        for(int i = 0; i < (int)nums.size(); i++) ans[i] = pref[i] * suff[i + 1];
        
        // cout << "----------------------------------------------------------------------\n";
        
        return ans;
    }
};