// https://practice.geeksforgeeks.org/problems/three-way-partitioning/0

#include "bits/stdc++.h"
using namespace std;

class Solution {   
public:
    //Function to partition the array around the range such 
    //that array is divided into three parts.
    void threeWayPartition(vector<int>& arr,int a, int b) {
        // code here 
        // < [a..b] < 
        /*
            17
            1 1 7 10 5 6 0 0 4 9 2 2 3 6 10 4 0
            2 9
            use this input to understand!!
        */
        int lo = 0, i = 0, hi = arr.size() - 1;
        while(i <= hi) {
            if(arr[i] < a) swap(arr[lo++], arr[i++]);
            else if(arr[i] > b) swap(arr[i], arr[hi--]);
            else i++;
        }
        // cout << "lo --> " << lo << " i --> " << i << " hi --> " << hi << "\n";
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int& x : arr) cin >> x;
    int a, b;
    cin >> a >> b;

    Solution sol;
    sol.threeWayPartition(arr, 2, 9);

    for(int& x : arr) cout << x << " ";
    cout << "\n";
}