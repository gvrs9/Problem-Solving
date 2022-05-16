class Solution {
public:
    void setZeroes(vector<vector<int> >& v) {
        int m = v.size(), n = v[0].size();
        // bool rows[m] = {false}, cols[n] = {false};
        
        vector<bool> rows(m, false), cols(n, false);
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(v[i][j] == 0) {
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }
        /*
        for(bool x : cols) {
            if(x)
                cout << 1 << " ";
            else
                cout << 0 << " ";
        }
        cout << "\n";
        for(bool x : rows) {
            if(x)
                cout << 1 << " ";
            else
                cout << 0 << " ";
        }
        */
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(rows[i] || cols[j]) v[i][j] = 0;
            }
        }
    }
};