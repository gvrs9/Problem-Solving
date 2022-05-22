class Solution {
private:
    bool isSafe(int row, int col, int m, int n) {
        return (row >= 0) && (row < m) && (col >= 0) && (col < n);
    }
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, bool& flag, int m, int n) {
        for(int k = 0; k < 4; k++) {
            if(isSafe(i + vp[k].first, j + vp[k].second, m, n) && grid2[i + vp[k].first][j + vp[k].second]) {
                if(grid2[i + vp[k].first][j + vp[k].second] != grid1[i + vp[k].first][j + vp[k].second]) {
                    flag = true;
                }
                grid2[i + vp[k].first][j + vp[k].second] = 0;
                dfs(grid1, grid2, i + vp[k].first, j + vp[k].second, flag, m, n);
            }
        }
    }
public:
    vector<pair<int, int> > vp = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid2.size(), n = grid2[0].size();
        int cnt = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid2[i][j] && grid1[i][j]) {
                    cnt++;
                    bool flag = false;
                    grid2[i][j] = 0;
                    dfs(grid1, grid2, i, j, flag, m, n);
                    if(flag) cnt--;
                }
            }
        }
        
        return cnt;
    }
};