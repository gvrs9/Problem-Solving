// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    private:
        bool isSafe(int row, int col, int m, int n) {
            return (row >= 0) && (row < m) && (col >= 0) && (col < n);
        }
        void dfs(vector<vector<char> >& grid, int i, int j, int& zeroCnt, int m, int n) {
            for(int k = 0; k < 8; k++) {
                if(isSafe(i + vp[k].first, j + vp[k].second, m, n) && grid[i + vp[k].first][j + vp[k].second] == '1') {
                    grid[i + vp[k].first][j + vp[k].second] = '0';
                    zeroCnt++;
                    dfs(grid, i + vp[k].first, j + vp[k].second, zeroCnt, m, n);
                }
            }
        }
    public:
    vector<pair<int, int> > vp = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), zeroCnt = 0;
        int cnt = 0;
        for(int i = 0; i < m; i++) {
            if(zeroCnt == m * n) break;
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1') {
                    grid[i][j] = '0';
                    zeroCnt++;cnt++;
                    dfs(grid, i, j, zeroCnt, m, n);
                }
            }
        }
        return cnt;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends