class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;
        for(string str : strs) {
            string tempStr = str;
            sort(tempStr.begin(), tempStr.end());
            umap[tempStr].push_back(str);
        }
        
        vector<vector<string>> ans;
        for(auto [x, y]: umap) ans.push_back(y);
        
        return ans;
    }
};