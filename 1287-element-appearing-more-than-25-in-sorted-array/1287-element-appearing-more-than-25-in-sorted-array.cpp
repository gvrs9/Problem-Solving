class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int cal = n / 4;
        unordered_map<int, int> mp;

        for(int& x : arr) {
            mp[x]++;
            if(mp[x] > cal) return x;
        }

        return -1;
    }
};