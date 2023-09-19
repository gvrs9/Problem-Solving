class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> umap;
        for(int i = 0; i < n; i++) {
            string str = strs[i];
            sort(str.begin(), str.end());
            umap[str].push_back(strs[i]);
        }
        
        vector<vector<string>> ans;
        for(auto it: umap) ans.push_back(it.second);
        
        return ans;
    }
};