class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(), -1);
        unordered_map<int, int> umap;
        
        for(int i = 0; i < (int)nums1.size(); i++) umap[nums1[i]] = i;
        for(int i = 0; i < (int)nums2.size(); i++) {
            if(umap.find(nums2[i]) == umap.end()) continue;
            for(int j = i; j < (int)nums2.size(); j++) {
                if(nums2[i] < nums2[j]) {
                    ans[umap[nums2[i]]] = nums2[j];
                    break;
                }
            }
        }
        
        return ans;
    }
};

/*
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // Brute Force!! O(n*m) -> T.C && space complexity of O(m) where n and m nums1.size() and nums2.size()
        vector<int> ans(nums1.size(), -1);
        unordered_map<int, int> umap;
        
        for(int i = 0; i < (int)nums2.size(); i++) umap[nums2[i]] = i; // {value, index} map!!
        for(int i = 0; i < (int)nums1.size(); i++) {
            int pos = umap[nums1[i]];
            pos += 1; // we don't need to check itself!!
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
*/