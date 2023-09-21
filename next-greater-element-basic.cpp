#include "iostream"
#include "vector"
#include "stack"
#include <stack>
using namespace std;

vector<int> next_greater_element_other_method(int arr[], int size) {
	vector<int> ans(size, -1);
	stack<int> stk;

	// Traversing the array from reverse
	for (int i = size - 1; i >= 0; i--) {
		int currElement = arr[i];
		while (!stk.empty() && currElement >= arr[stk.top()]) stk.pop(); // Consider having >= or just > based on whether the given array has unique elements or repeated elements. For unique, we can just keep >.
		int res = stk.empty() ? -1 : arr[stk.top()];
		ans[i] = res;
		stk.push(i);
	}

	return ans;
}

vector<int> next_greater_element(int arr[], int size) {
	vector<int> ans(size, -1);
	stack<int> stk;

	for (int i = 0; i < size; i++) {
		int currElement = arr[i];
		while (!stk.empty() && currElement >= arr[stk.top()]) { // Consider having >= or just > based on whether the given array has unique elements or repeated elements. For unique, we can just keep >.
			int index = stk.top();
			stk.pop();
			ans[index] = currElement;
		}
		stk.push(i);
	}

	return ans;
}

int main() {
	int t;
	cin >> t;

	/*
		Sample I/P:
			4
			8
			4 3 2 1 5 7 0 6
			5
			4 5 2 3 1
			5
			1000 1 2 3 7
			11
			10 100 25 27 200 3 5 4 1 36 475

		Sample O/P:
			5 5 5 5 7 -1 6 -1
			5 5 5 5 7 -1 6 -1
			_____________________________
			5 -1 3 -1 -1
			5 -1 3 -1 -1
			_____________________________
			-1 2 3 7 -1
			-1 2 3 7 -1
			_____________________________
			100 200 27 200 475 5 36 36 36 475 -1
			100 200 27 200 475 5 36 36 36 475 -1
			_____________________________

	*/

	while (t--) {
		int size;
		cin >> size;

		int arr[size];
		for (int& x : arr) cin >> x;

		vector<int> ans1 = next_greater_element(arr, size);
		vector<int> ans2 = next_greater_element_other_method(arr, size);

		for (int x : ans1) cout << x << " ";
		cout << "\n";
		for (int x : ans2) cout << x << " ";

		cout << "\n";
		cout << "_____________________________\n";
	}

	return 0;
}
