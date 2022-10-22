class Solution {
    public void setZeroes(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        boolean zeroRow = false, zeroCol = false;
        /*
            [[1, 1, 1, 1], [2, 0, 1, 1], [0, 2, 1, 1]] --> consider this example to understand why did you i take the two boolean variables!!
        */
        for(int i = 0; i < m; i++) { // marking phase!!
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    if(i == 0) zeroRow = true;
                    if(j == 0) zeroCol = true;
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = 1; i < m; i++) { // zeroing whole matrix from 1st row 1st col to last row last col. 0th row and 0th col are handled later
            for(int j = 1; j < n; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
        }
        
        if(zeroRow) { // zeroing 0th row!!
            for(int i = 0; i < n; i++) matrix[0][i] = 0;
        }
        if(zeroCol) { // zeroing 0th col!!
            for(int i = 0; i < m; i++) matrix[i][0] = 0;
        }
    }
}