class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1) return {{1}};
        vector<vector<int>> ans;
        ans.push_back({1});ans.push_back({1, 1});
        if(numRows == 2) return ans;
        numRows -= 2;
        int i = 2;
        while(numRows--) {
            vector<int> temp(i + 1, 0);
            for(int j = 0; j < i + 1; j++) {
                if(j == 0 || i == j) temp[j] = 1;
                else temp[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
            ans.push_back(temp);
            i++;
        }
        return ans;
    }
};