class Solution{
    public:
    int lenOfLongSubarr(int arr[], int n, int k) {
        // Complete the function
        // 10 5 2 7 1 9
        // 15
        // subarray len -> 0
        
        /*int longestSubarrayLength = 0, sum = 0;
        for(int i = 0; i < N; i++) {
            sum = 0;
            for(int j = i; j < N; j++) {
                sum += A[j];
                if(sum == K) longestSubarrayLength = max(longestSubarrayLength, j - i + 1);
            }
        }
        return longestSubarrayLength;*/
        
        /*
        
        // Optimised Approach -> Prefix Sum. Note: This only works if arr[i] doesn't have 0's
        
        map<int, int> mp;
        int longestSubarrayLength = 0, prefixSum = 0;
        
        for(int i = 0; i < n; i++) {
            prefixSum += arr[i];
            if(prefixSum == k) longestSubarrayLength = max(longestSubarrayLength, i + 1);
            mp[prefixSum] = i;
            if(mp[prefixSum - k]) longestSubarrayLength = max(longestSubarrayLength, i - mp[prefixSum - k]);
        }
        return longestSubarrayLength;
        
        */
        
        // Optimised Approach -> Prefix Sum. Note: This works if arr[i] have 0's.
        
        // map<int, int> mp;
        unordered_map<int, int> mp; //! Note: If using unordered_map, in the avg case, the T.C of this overall solution will be, O(N * 1) -> O(N). But in worst case, due to internal collisions in the unordered_map, we will have the overall T.C -> O(N * N) -> O(N^2). But if we use just map, the worst case T.C -> of this solution will be O(N*logN).
        int longestSubarrayLength = 0, prefixSum = 0;
        
        for(int i = 0; i < n; i++) {
            prefixSum += arr[i];
            if(prefixSum == k) longestSubarrayLength = max(longestSubarrayLength, i + 1);
            if(mp.find(prefixSum) == mp.end()) mp[prefixSum] = i;
            if(mp.find(prefixSum - k) != mp.end()) longestSubarrayLength = max(longestSubarrayLength, i - mp[prefixSum - k]);
        }
        return longestSubarrayLength;
    }
};
