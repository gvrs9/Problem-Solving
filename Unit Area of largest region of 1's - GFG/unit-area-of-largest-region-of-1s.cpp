// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    private:
        bool isSafe(vector<vector<int> >& grid,int row, int col, int m, int n) {
            return (row >= 0) && (row < m) && (col >= 0) && (col < n);
        }
        void dfs(vector<vector<int> >& grid,int i, int j, int& indiCnt,int& zeroCnt, int m, int n) {
            for(int k = 0; k < 8; k++) {
                if(isSafe(grid, i + vp[k].first, j + vp[k].second, m, n) && grid[i + vp[k].first][j + vp[k].second]) {
                    grid[i + vp[k].first][j + vp[k].second] = 0;
                    zeroCnt++;
                    indiCnt++;
                    dfs(grid, i + vp[k].first, j + vp[k].second, indiCnt, zeroCnt, m, n);
                }
            }
        }
    public:
    vector<pair<int, int> > vp = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    int findMaxArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), zeroCnt = 0;
        int maxCnt = INT_MIN;
        
        for(int i = 0; i < m; i++) {
            if(zeroCnt == m * n) break;
            for(int j = 0; j < n; j++) {
                if(grid[i][j]) {
                    grid[i][j] = 0;
                    zeroCnt++;
                    int indiCnt = 1;
                    dfs(grid, i, j, indiCnt, zeroCnt, m, n);
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