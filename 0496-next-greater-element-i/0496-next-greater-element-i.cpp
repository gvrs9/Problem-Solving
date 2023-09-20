class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(), -1);
        unordered_map<int, int> umap;
        
        for(int i = 0; i < (int)nums2.size(); i++) umap[nums2[i]] = i;
        for(int i = 0; i < (int)nums1.size(); i++) {
            // int x = umap[nums1[i]];
            int pos = umap[nums1[i]];
            
            while(pos < (int)nums2.size()) {
                if(nums1[i] < nums2[pos]) {
                    ans[i] = nums2[pos];
                    break;
                }
                pos++;
            }
        }
        
        return ans;
    }
};