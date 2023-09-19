class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;
        for(string str : strs) {
            string tempStr = str;
            /*
            int chFreq[26] = {0};
            for(int ch : str) chFreq[ch - 'a']++;
            string keyString;
            for(int x : chFreq) keyString += (x + '0');
            */
            
            char chFreq[26];
            for(char& ch : chFreq) ch = 0;
            for(char ch : str) chFreq[ch - 'a']++;
            string keyString = "";
            for(char ch : chFreq) keyString += ch;
            cout << keyString << "\n";
            umap[keyString].push_back(str);
        }
        
        vector<vector<string>> ans;
        for(auto [x, y]: umap) ans.push_back(y);
        
        return ans;
    }
};

/*
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Time complexity: O(nmlogm)
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
*/