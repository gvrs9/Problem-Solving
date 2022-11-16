#include "iostream"
using namespace std;

int n;

void count_sort(int arr[], int k) // this algo is not for negative elements and T.C -> O(n + k) and S.C -> O(n + k)
{
    int count[k] = {0}; // since eles range is btw 0 to k - 1 and this array is to store the frequencies of the main array arr!!
    for (int i = 0; i < n; i++)
        count[arr[i]]++;
    for (int i = 1; i < k; i++)
        count[i] += count[i - 1]; // cumulative sum and  here this modification indicates that for every i, count[i] elements are there that are smaller than or equal to i; ex: we have the array = { 1,4,4,1,0,1 } and k = 5, so the count[] after cumulative sum would be -> { 1, 4, 4, 4. 6}. So, for i = 1 in the modified count array, we have 4 elements that are smaller than or equal to i(i.e., i = 1 here) -> eles <= 1 are {0, 1, 1, 1}. This step ensures that we know how many eles are actually smaller than or equal to i;
    int output[n];                // to store the sorted elements
    for (int i = n - 1; i >= 0; i--)
    {                                       // reverse iteration of this main array arr[] is to ensure the realtive order of the same elements in the after sorted array also thus making them stable!! Remember that we can also iterate from o to n - 1 but that does not maintain the relative order of the elements thus making this algo unstable!!
        output[count[arr[i]] - 1] = arr[i]; // assigning the actual element in the correct sorted position in the output array. Due to this step, we do reverse iteration to maintain stability of this algorithm as we are directly assigning the element arr[i] to the output array. If this array of integers would have been some ex: vector<pair<int, string>> then imagine if not in reverse iteration then this(algo) would be assigning same first value but different second valued elemnts in differnt order but not in their relative order. Also we are subtracting 1 since the ouput array is 0 indexed!!
        count[arr[i]]--;                    // decrementing the count of the particular ele after putting it in the output array
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i]; // copying the sorted order to the original array!!
}

/**
 * Important points of counting sort:
 * 1. T.C and S.C -> O(n + k) in worst case and average case!!
 * 2. Best Case Complexity - It occurs when there is no sorting required, i.e. the array is already sorted. The best-case time complexity of counting sort is O(n + k).
 * 3. Average Case Complexity - It occurs when the array elements are in jumbled order that is not properly ascending and not properly descending. The average case time complexity of counting sort is O(n + k).
 * 4. Worst Case Complexity - It occurs when the array elements are required to be sorted in reverse order. That means suppose you have to sort the array elements in ascending order, but its elements are in descending order. The worst-case time complexity of counting sort is O(n + k).
 * 5. It is Stable sorting algorithm!!
 * 6. The larger the range of elements, the larger the space complexity.
 */

int main()
{
    cin >> n;
    int arr[n];
    for (int &x : arr)
        cin >> x;
    int k; // range of ele in btw 0 to k - 1
    cin >> k;
    count_sort(arr, k);
    for (int &x : arr)
        cout << x << " ";
}