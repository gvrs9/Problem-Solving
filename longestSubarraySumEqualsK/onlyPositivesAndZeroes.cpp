int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
	int longestSubarrayLength = 0;
    long long unsigned int currSum = a[0];
    int i = 0, j = 0, n = a.size();

    while(j < n) {
        /*
            8 10
            5 2 2 9 1 1 1 65

            Expected O/P -> 2.
        */
        while(i <= j && currSum > k) currSum -= a[i++]; // Why while? consider this above case.
        if(currSum == k) longestSubarrayLength = max(longestSubarrayLength, j - i + 1);
        j++;
        if(j < n) currSum += a[j];
    }

    return longestSubarrayLength;
}
