//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution {
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int maxiCnt = 0, ansIndex = -1;
	    for(int i = 0; i < n; i++) {
	        int currOneCnt = (upper_bound(arr[i].begin(), arr[i].end(), 1) - lower_bound(arr[i].begin(), arr[i].end(), 1));
	        if(maxiCnt < currOneCnt) {
	            maxiCnt = currOneCnt;
	            ansIndex = i;
	        }
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