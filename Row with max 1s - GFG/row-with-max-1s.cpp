//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution {
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    // O(N*log(M))
	    /*int maxiCnt = 0, ansIndex = -1;
	    for(int i = 0; i < n; i++) {
	        int currOneCnt = (upper_bound(arr[i].begin(), arr[i].end(), 1) - lower_bound(arr[i].begin(), arr[i].end(), 1));
	        if(maxiCnt < currOneCnt) {
	            maxiCnt = currOneCnt;
	            ansIndex = i;
	        }
	    }
	    return ansIndex;*/
	    
	    //O(N + M)
	    // Abe chodu, question dhyan se padle!! Yaha Two Pointer Concept use kar sakte hai!!
	    // har ek row sorted hai and most important is that, column ka size, har ek row mein fixed(same) hai. So, we can just keep track of row and columns.
	    // i maintains the row index from first and j the column index from last(as we know that every column is sorted).
	    // decrement j and keep updating the ansIndex(this will store the row that will have max number of 1's) until you hit 0.
	    // if 0 is encountered, then increment the i which keeps track of the row number.
	    // consider the example and dry run the test cases. Samajh aa jayega bsdk!!
	    int i = 0, j = m - 1;
	    int ansIndex = -1;
	    while(i < n && j >= 0) {
	        if(arr[i][j]) j--, ansIndex = i;
	        else i++;
	    }
	    return ansIndex;
	}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends