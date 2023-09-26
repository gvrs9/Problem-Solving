class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // We use only the output array for first calculating the prefix product and then to calculate te the suffix product and simultaneously the prefix * suffix product.
        // O(n) -> T.C & S.C -> O(1)
        
        vector<int> ans(nums.size());
        ans[0] = 1;
        // calculating the prefix product
        for(int i = 1; i < (int)nums.size(); i++) ans[i] = ans[i - 1] * nums[i - 1];
        
        // So for [1,2,3,4], the ans will now look like [1,1,2,6]. We don't need to store for the 4th ele as we don't require it and for it, the suffix product is 1.
        
        // we now calculate the suffix product and simultaneously calculate the prefix * suffix product. 
        // Take suffix product variable "suffix" and set it to 1. Since we k/t, for the (n - 1)th ele of nums[], suffix product is 1 as there is no ele after it.
        
        int suffix = 1;
        for(int i = nums.size() - 1; i >= 0; i--) {
            int prefix = ans[i];
            ans[i] = prefix * suffix; // store the product in the same position.
            suffix *= nums[i]; // update the suffix.
        }
        
        return ans;
    }
};

/*
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // prefix sum using prefix array and suffix(or postfix) array
        // O(n) -> T.C & S.C -> O(n)
        
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
*/


/*
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    
        // Same as above prefix and suffix array technique.
        // O(n) -> T.C & S.C -> O(n)
        
        vector<int> pref(nums.size(), 0);
        
        pref[0] = 1;
        
        for(int i = 1; i < (int)nums.size(); i++) pref[i] = pref[i - 1] * nums[i - 1];
                
        vector<int> suff(nums.size(), 0);
        
        suff[nums.size() - 1] = 1;
        
        for(int i = (int)nums.size() - 2; i>= 0; i--) suff[i] = suff[i + 1] * nums[i + 1];
        
        vector<int> ans(nums.size(), 0);
        
        for(int i = 0; i < (int)nums.size(); i++) ans[i] = pref[i] * suff[i];
        
        return ans;
    }
};
*/
