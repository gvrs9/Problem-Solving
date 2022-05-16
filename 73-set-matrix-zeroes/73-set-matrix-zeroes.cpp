class Solution {
private:
    void fillZeroes(vector<vector<int> >& v, int i, int j, int m, int n) {
        for(int k = 0; k < m; k++) v[k][j] = 0;
        for(int k = 0; k < n; k++) v[i][k] = 0;
    }
public:
    void setZeroes(vector<vector<int> >& v) {
        vector<pair<int, int> > vp;
        for(int i = 0; i < (int)v.size(); i++)
            for(int j = 0; j < (int)v[0].size(); j++)
                if(!v[i][j])
                    vp.push_back({i, j});
        for(int i = 0; i < (int)vp.size(); i++) {
            int ind1 = vp[i].first, ind2 = vp[i].second;
            fillZeroes(v, ind1, ind2, v.size(), v[0].size());
        }
    }
};