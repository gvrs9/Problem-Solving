class Solution {
public:
    void setZeroes(vector<vector<int> >& v) {
        // O(M * N) -> Time && O(1) ->Space
        //Similar to O(M + N) space's Solution but instead we here consider the two arrays as the 0th row and 0th col.
        bool rowZero = false, colZero = false;
        
        // determine which rows/cols to be zeroed out!!
        
        for(int i = 0; i < v.size(); i++) {
            for(int j = 0; j < v[0].size(); j++) {
                if(v[i][j] == 0) {
                    if(i == 0) rowZero = true; // used for zeroing the 0th row as we know the two arrays of the 0th row and 0th col coincide at v[0][0]. So need to handle it seperately
                    if(j == 0) colZero = true; // used for zeroing the 0th col as we know the two arrays of the 0th row and 0th col coincide at v[0][0]. So need to handle it seperately
                    // set for 0th row and variable col as 0
                    v[0][j] = 0;
                    // set for variable row and 0th col as 0 
                    v[i][0] = 0;
                }
            }
        }
            
        // zeroing out from 1,1 to m,n. 0,0 is handled at last
        for(int i = 1; i < v.size(); i++) {
            for(int j = 1; j < v[0].size(); j++) {
                if(v[i][0] == 0 || v[0][j] == 0) { // setting curr v[i][j] value according to v[i][0] (0th row) or v[0][j] (0th col)
                    v[i][j] = 0;
                }
            }
        }
            
        if(colZero) { // used for zeroing out the 0th col
            for(int i = 0; i < v.size(); i++) {
                v[i][0] = 0;
            }
        }
            
        if(rowZero) { // used to zeroing out the 0th row
            for(int j = 0; j < v[0].size(); j++) {
                v[0][j] = 0;
            }
        }
    }
};

// O(M * N) -> Time Complexity && O(M + N) -> Space Complexity
/*
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
        
        // for(bool x : cols) {
        //     if(x)
        //         cout << 1 << " ";
        //     else
        //         cout << 0 << " ";
        // }
        // cout << "\n";
        // for(bool x : rows) {
        //     if(x)
        //         cout << 1 << " ";
        //     else
        //         cout << 0 << " ";
        // }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(rows[i] || cols[j]) v[i][j] = 0;
            }
        }
    }
};
*/

// O(M * N) -> Time && O(M * N) -> Space
/*
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
*/