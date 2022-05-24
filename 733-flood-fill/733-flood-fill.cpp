class Solution {
private:
    bool isSafe(vector<vector<int> >& image, int val, int row, int col, int m, int n) {
        return (row < 0 || row >= m || col < 0 || col >= n || val != image[row][col]) ? false : true;
    }
    void dfs(vector<vector<int> >& image, int val, int sr, int sc, int newColor, int m, int n) {
        for(int k = 0; k < 4; k++) {
            if(isSafe(image, val, sr + vp[k].first, sc + vp[k].second, m, n)) {
                image[sr + vp[k].first][sc + vp[k].second] = newColor;
                dfs(image, val, sr + vp[k].first, sc + vp[k].second, newColor, m, n);
            }
        }
    }
public:
    vector<pair<int, int> > vp = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size(), n = image[0].size(), val = image[sr][sc];
        if(image[sr][sc] != newColor) image[sr][sc] = newColor, dfs(image, val, sr, sc, newColor, m, n);
        
        return image;
    }
};