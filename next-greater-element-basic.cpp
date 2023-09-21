#include "iostream"
#include "vector"
#include "stack"
using namespace std;

vector<int> next_greater_element(int arr[], int size) {
	vector<int> ans(size, -1);
	stack<int> stk;

	for (int i = 0; i < size; i++) {
		int currElement = arr[i];
		while (!stk.empty() && currElement > arr[stk.top()]) {
			int index = stk.top();
			stk.pop();
			ans[index] = currElement;
		}
		stk.push(i);
	}

	return ans;
}

int main() {
	int size;
	cin >> size;

	int arr[size];
	for (int& x : arr) cin >> x;

	vector<int> ans = next_greater_element(arr, size);

	for (int x : ans) cout << x << " ";

	return 0;
}
