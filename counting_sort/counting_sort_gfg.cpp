// https://practice.geeksforgeeks.org/batch/cip-1/track/DSA-Foundation-Sorting/problem/counting-sort

// Done using count sort!!

#include "bits/stdc++.h"
using namespace std;

class Solution {
    public:
    //Function to arrange all letters of a string in lexicographical 
    //order using Counting Sort.
    string countSort(string s){
        // code here
        string output = s;
        int n = s.size();
        int count[26] = {0};
        for(char x : s) count[x - 'a']++;
        for(int i = 1; i < 26; i++) count[i] += count[i - 1];
        for(int i = n - 1; i >= 0; i--) {
            output[count[s[i] - 'a'] - 1] = s[i];
            count[s[i] - 'a']--;
        }
        return output;
    }
};

int main() {
    Solution sol;
}