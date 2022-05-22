class Solution {
private:
    bool isSafe(int row, int col, int m, int n) {
        return (row >= 0) && (row < m) && (col >= 0) && (col < n);
    }
    void dfs(vector<vector<int> >& land, int i, int j, pair<int, int>& p,int& zeroCnt, int m, int n) {
        for(int k = 0; k < 4; k++) {
            if(isSafe(i + vp[k].first, j + vp[k].second, m, n) && land[i + vp[k].first][j + vp[k].second]) {
                zeroCnt++;
                land[i + vp[k].first][j + vp[k].second] = 0;
                if((i + j) < ((i + vp[k].first) + (j + vp[k].second))) {
                    p.first = i + vp[k].first;
                    p.second = j + vp[k].second;
                }
                dfs(land, i + vp[k].first, j + vp[k].second, p, zeroCnt, m, n);
            }
        }
    }
public:
    vector<pair<int, int> > vp = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size(), n = land[0].size(), zeroCnt = 0;
        vector<vector<int> > v;
        
        for(int i = 0; i < m; i++) {
            if(zeroCnt == m * n) break;
            for(int j = 0; j < n; j++) {
                if(land[i][j]) {
                    zeroCnt++;
                    land[i][j] = 0;
                    vector<int> tempVec;
                    tempVec.push_back(i), tempVec.push_back(j);
                    pair<int, int> p = {i, j};
                    
                    dfs(land, i, j, p, zeroCnt, m, n);
                    
                    tempVec.push_back(p.first), tempVec.push_back(p.second);
                    v.push_back(tempVec);
                }
            }
        }
        
        return v;
    }
};