class Solution {
private:
    bool isSafe(int row, int col, int m, int n) {
        return (row >= 0) && (row < m) && (col >= 0) && (col < n);
    }
    void dfs(vector<vector<char> >& grid, int i, int j, int& zeroCnt, int m, int n) {
        for(int k = 0; k < 4; k++) {
            if(isSafe(i + vp[k].first, j + vp[k].second, m, n) && grid[i + vp[k].first][j + vp[k].second] == '1') {
                zeroCnt++;
                grid[i + vp[k].first][j + vp[k].second] = '0';
                dfs(grid, i + vp[k].first, j + vp[k].second, zeroCnt, m, n);
            }
        }
    }
public:
    vector<pair<int, int> > vp = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    int numIslands(vector<vector<char> >& grid) {
        int m = grid.size(), n = grid[0].size(), zeroCnt = 0;
        int cnt = 0;
        
        for(int i = 0; i < m; i++) {
            if(zeroCnt == m * n) break;
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1') {
                    grid[i][j] = '0';
                    zeroCnt++;
                    cnt++;
                    dfs(grid, i, j, zeroCnt, m, n);
                }
            }
        }
        
        return cnt;
    }
};