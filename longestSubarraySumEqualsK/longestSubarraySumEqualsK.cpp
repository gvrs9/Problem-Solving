#include "iostream"
#include "vector"
#include "unordered_map"
#include "algorithm"
#include <algorithm>
using namespace std;

int longestSubarrayWithSumKBruteSlightOptimised(vector<int> a, long long k) {
	// Brute Force
	// Works for positives,negatives and zeroes.
	int maximumLength = 0;
	for (int i = 0; i < (int)a.size(); i++) {
		int sum = 0;
		for (int j = i; j < (int)a.size(); j++) {
			sum += a[j];
			if (sum == k) maximumLength = max(maximumLength, (j - i + 1));
		}
	}
	return maximumLength;
}

int longestSubarrayWithSumKBetterInOneCaseAndOptimalInOther(vector<int> a, long long k) {
	// Works for positives, negatives and Zeroes case.
	// Remember, this method is optimal when the case is the array contains positives, negatives and Zeroes case.
	// When there is only positives and zeroes case, then this solution is better solution but not optimal.
	// Hashing. Precisely, Prefix Sum Technique.
	// T.C -> O(nlogn) when we use a map. When we use an unordered_map, T.C -> ~O(n*n) -> O(n^2) in the worst case when there are collisions due to which it takes up 'n' search time for each ele. So for 'n' eles, when collisions is O(n*n) -> O(n^2). And O(n*1) when in the average case, where the 1 being the search time in the map.
	// S.C -> O(n). For every ele in the array if we store that ele in the map.
	// {prefixSum, index}
	unordered_map<long long, int> prefixSum;
	int maximumLength = 0;
	long long sum = 0;

	for (int i = 0; i < (int)a.size(); i++) {
		sum += a[i];

		if (sum == k) maximumLength = max(maximumLength, i + 1);

		long long remaining = sum - k;
		if (prefixSum.find(remaining) != prefixSum.end()) {
			int indexOfDiff = prefixSum[remaining];
			int currLen = i - indexOfDiff;
			maximumLength = max(maximumLength, currLen);
		}

		// prefixSum[sum] = i; // This will only work when we have array of positives and have no zeroes in it. So for ex: [2, 0, 0, 0, 3] and k = 3, we can see that doing this `prefixSum[sum] = i` will cause our index to update which will result in the maximumLength = 1. But that's wrong. Why? Because, [0, 0, 0, 3] is the subarray which is the longest and gives the length 4!! So for that we need to update our map only when the prefixSum map does not have the "sum" in it. If it exists then don't update. This way, we make sure that we get the longest subarray of sum k.

		if (prefixSum.find(sum) == prefixSum.end()) prefixSum[sum] = i; // This works when we have 0's too in the array.
	}

	return maximumLength;
}

int longestSubarrayWithSumKOptimal(vector<int> a, long long k) {
	// Note: This only optimal solution and works for the case where the array only contains positives and zeroes.
	// T.C -> O(n) and S.C -> O(1)
	// Optimal Solution for the case where the array contains only positives and zeroes
	// Two Pointer Approach. T.C -> O(n) & S.C -> O(1)

	int left = 0, right = 0;
	int maximumLength = 0;
	long long sum = 0;

	/*
	// My Code
	while (right < (int)a.size()) {
		sum += a[right];

		while (sum > k) {
			sum -= a[left];
			left++;
		}

		while (right < (int)a.size() && sum == k) {
			maximumLength = max(maximumLength, right - left + 1);
			right++;
			sum += a[right];
		}

		if (right < left) right = left;
		else right++;
	}
	*/

	// Clear and understandable code!!
	while (right < (int)a.size()) {
		sum += a[right];

		while (sum > k) {
			sum -= a[left];
			left++;
		}

		if (sum == k) maximumLength = max(maximumLength, right - left + 1);

		right++;
	}

	return maximumLength;
}

int main() {
	int t;
	cin >> t;

	/*
		Sample Input:

		7
		7 3
		1 2 3 1 1 1 1
		4 2
		1 2 1 3
		5 2
		2 2 4 1 2
		10 3
		1 2 3 1 1 1 1 4 2 3
		10 9
		1 2 3 4 5 6 7 9 8 0
		5 3
		2 0 0 0 3
		6 3
		2 5 0 0 0 3

		Sample Output:

		3
		3
		3
		_____________________________
		1
		1
		1
		_____________________________
		1
		1
		1
		_____________________________
		3
		3
		3
		_____________________________
		3
		3
		3
		_____________________________
		4
		4
		4
		_____________________________
		4
		4
		4
		_____________________________

	*/

	while (t--) {
		int n;
		long long k;
		cin >> n >> k;

		vector<int> a(n);
		for (int& x : a) cin >> x;

		int maxiLength1 = longestSubarrayWithSumKBruteSlightOptimised(a, k);
		cout << maxiLength1 << "\n";

		int maxiLength2 = longestSubarrayWithSumKBetterInOneCaseAndOptimalInOther(a, k);
		cout << maxiLength2 << "\n";

		int maxiLength3 = longestSubarrayWithSumKOptimal(a, k);
		cout << maxiLength3 << "\n";

		cout << "_____________________________\n";
	}
	return 0;
}