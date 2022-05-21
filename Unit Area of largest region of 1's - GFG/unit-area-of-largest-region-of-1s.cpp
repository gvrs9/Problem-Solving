// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    private:
        bool isSafe(vector<vector<int> >& grid, vector<vector<bool> >& visited, int row, int col, int m, int n) {
            return (row >= 0) && (row < m) && (col >= 0) && (col < n) && (grid[row][col] && !visited[row][col]);
        }
        void dfs(vector<vector<int> >& grid, vector<vector<bool> >& visited, int i, int j, int& indiCnt, int m, int n) {
            visited[i][j] = true;
            
            for(int k = 0; k < 8; k++) {
                if(isSafe(grid, visited, i + vp[k].first, j + vp[k].second, m, n)) {
                    indiCnt++;
                    dfs(grid, visited, i + vp[k].first, j + vp[k].second, indiCnt, m, n);
                }
            }
        }
    public:
    vector<pair<int, int> > vp = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    int findMaxArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        int maxCnt = INT_MIN;
        // vp = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] && !visited[i][j]) {
                    int indiCnt = 1;
                    dfs(grid, visited, i, j, indiCnt, m, n);
                    maxCnt = max(maxCnt, indiCnt);
                }
            }
        }
        
        return maxCnt;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends