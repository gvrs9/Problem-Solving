class Solution {
public:
    int longestMountain(vector<int>& arr) {
        if(arr.size() < 3) return 0;
        int longestLen = 0;
        int up(0), down(0), i(1);
        int n = arr.size();
        while(i < n) {
            while(i < n && up == 0 && (arr[i - 1] > arr[i] || arr[i - 1] == arr[i])) i++;
            while(i < n && arr[i - 1] == arr[i]) i++;
            int up = 0, down = 0;
            while(i < n && arr[i - 1] < arr[i]) up++, i++;
            while(up != 0 && i < n && arr[i - 1] > arr[i]) down++, longestLen = max(longestLen, up + down + 1), i++;
        }
        return longestLen;
    }
};