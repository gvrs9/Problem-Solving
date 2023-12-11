class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return arr[0];
        int cal = n / 4;
        int freq = 1;

        for(int i = 1; i < n; i++) {
            if(arr[i - 1] == arr[i]) {
                freq++;
                if(freq > cal) return arr[i];
            } else {
                freq = 1;
            }
        }

        return -1;
    }
};