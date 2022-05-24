class Solution {
private:
    int dfs(vector<vector<int> >& grid, int i, int j, int m, int n) {
        if(i < 0 || i >= m || j < 0 || j >= n || !grid[i][j] || grid[i][j] == 2) return 0;
        int cnt = 4;
        grid[i][j] = 2;
        if(j > 0 && grid[i][j - 1]) cnt--;
        if(i > 0 && grid[i - 1][j]) cnt--;
        if(j + 1 < n && grid[i][j + 1]) cnt--;
        if(i + 1 < m && grid[i + 1][j]) cnt--;
        cnt += dfs(grid, i, j - 1, m, n) + dfs(grid, i - 1, j, m, n) + dfs(grid, i, j + 1, m, n) + dfs(grid, i + 1, j, m, n);
        return cnt;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        /*
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j])
                    return dfs(grid, i, j, m, n); // O(m * n) time and stack space for space complexity
        */
        
        for(int i = 0; i < m; i++) { // O(m * n) time and O(1) space
            for(int j = 0; j < n; j++) {
                if(grid[i][j]) {
                    res += 4;
                    if(j > 0 && grid[i][j - 1]) res--;
                    if(i > 0 && grid[i - 1][j]) res--;
                    if(j + 1 < n && grid[i][j + 1]) res--;
                    if(i + 1 < m && grid[i + 1][j]) res--;
                }
            }
        }
        
        return res;
    }
};