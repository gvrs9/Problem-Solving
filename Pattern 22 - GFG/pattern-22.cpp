//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printSquare(int n) {
        // code here
        if(n == 1) {
            cout << "1" << "\n";
            return;
        }
        int i = n;
        while(i > 1) {
            int oddLoopingCount = 2 * i - 1;
            int diff = (2 * n - 1) - oddLoopingCount;
            if(diff) {
                int frontPrint = diff / 2, backPrint = diff / 2;
                int tempFrontPrint = n;
                while(frontPrint--) cout << tempFrontPrint-- << " ";
                int oddLooper = oddLoopingCount;
                while(oddLooper--) cout << i << " ";
                int tempBackPrint = n - backPrint + 1;
                while(backPrint--) cout << tempBackPrint++ << " ";
                cout << "\n";
            }else {
                int oddLooper = 2 * n - 1;
                while(oddLooper--) cout << i << " ";
                cout << "\n";
            }
            i--;
        }
            
        int frontPrint = n - 1, backPrint = n - 1;
        int tempFrontPrint = n, tempBackPrint = 2;
        while(frontPrint--) cout << tempFrontPrint-- << " ";
        cout << "1" << " ";
        while(backPrint--) cout << tempBackPrint++ << " ";
        cout << "\n";

        i = 2;
        while(i <= n) {
            int oddLoopingCount = 2 * i - 1;
            int diff = (2 * n - 1) - oddLoopingCount;
            if(diff) {
                int frontPrint = diff / 2, backPrint = diff / 2;
                int tempFrontPrint = n;
                while(frontPrint--) cout << tempFrontPrint-- << " ";
                int oddLooper = oddLoopingCount;
                while(oddLooper--) cout << i << " ";
                int tempBackPrint = n - backPrint + 1;
                while(backPrint--) cout << tempBackPrint++ << " ";
                cout << "\n";
            }else {
                int oddLooper = 2 * n - 1;
                while(oddLooper--) cout << i << " ";
                cout << "\n";
            }
            i++;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        ob.printSquare(n);
    }
    return 0;
}
// } Driver Code Ends