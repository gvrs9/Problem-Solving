class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int hsh1[101] = {0};
        int hsh2[101] = {0};
        
        for(int& x : nums1) hsh1[x]++;
        for(int& x : nums2) hsh2[x]++;
        
        int ans1 = 0, ans2 = 0;
        for(int& x : nums1) if(hsh2[x]) ans1++;
        for(int& x : nums2) if(hsh1[x]) ans2++;
        
        return {ans1, ans2};
    }
};