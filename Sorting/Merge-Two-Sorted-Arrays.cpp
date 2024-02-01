#include "iostream"
#include "algorithm"
using namespace std;

/* *
! Some useful information regarding pointers!
void func(int* ptr);

int array[5];
int* ptr = array; // valid, equivalent to 'ptr = &array[0]'
func(array); // equivalent to func(&array[0]);

*/

struct Result {
	int* ptr;
	int size;
};

Result merge_two_sorted_arrays(const int arr1[], const int arr2[], const int arr1Length, const int arr2Length) {
	Result result;
	int i = 0, j = 0, k = 0;
	int mergedSortedArraySize = arr1Length + arr2Length;
	int* mergedSortedArray = new int[mergedSortedArraySize];

	while (i < arr1Length && j < arr2Length) {
		if (arr1[i] <= arr2[j]) mergedSortedArray[k++] = arr1[i++];
		else mergedSortedArray[k++] = arr2[j++];
	}

	while (i < arr1Length) mergedSortedArray[k++] = arr1[i++];
	while (j < arr2Length) mergedSortedArray[k++] = arr2[j++];

	/*
	for(int& x : mergedSortedArray) cout << x << " ";
	cout << "\n----------------------------\n";
	*/

	result.ptr = mergedSortedArray;
	result.size = mergedSortedArraySize;

	return result;
}

int main() {
	int a, b;
	cin >> a >> b;
	int arr1[a], arr2[b];

	for (int& x : arr1) cin >> x;
	for (int& x : arr2) cin >> x;

	// Just to be sure. Never trust the user input! Do not consider this sorting for calulating the time complexity of the below merge_two_sorted_arrays() function!
	sort(arr1, arr1 + a);
	sort(arr2, arr2 + b);

	// cout << arr1 << "\n";
	// cout << arr2 << "\n";

	Result mergedSortedArray = merge_two_sorted_arrays(arr1, arr2, a, b);

	int* ptrToMergedArray = mergedSortedArray.ptr;
	int mergedSortedArraySize = mergedSortedArray.size;

	// cout << mergedSortedArraySize << "\n";

	// cout << *(ptrToMergedArray + 1) << "\n";

	for (int i = 0; i < mergedSortedArraySize; i++) cout << *(ptrToMergedArray + i) << " ";

	delete[] ptrToMergedArray;
}
