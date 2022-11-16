#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

// this is useful when no.of elements is large but the range of the elements is small!!
// T.C & S.C -> O(n + k) where n is the no.of ele and k being the range!!
// Stability is maintained and this algo does not involve comparision!!
// Negative numbers, containers and complex objects can also be taken as input but they should follow the constraints!!

void count_sort(int arr[], int n)
{
    int max = *max_element(arr, arr + n);
    int min = *min_element(arr, arr + n);
    int k = max - min + 1; // k or range.
    int count[k] = {0}, output[n];
    for (int i = 0; i < n; i++)
        count[arr[i] - min]++; // arr[i] - min to represent the individual indexes in the count array as the elemnts in the range. Ex: let the array arr has the eles in the range 3 - 9. So, why waste the array by creating 9 size array! Instead, we can represent the count array indexes as the eles in the range by subtracting with min ele. ex: min = 3 in the array having the eles range 3 - 9 so 0th index in the count[] represents 3 and 1st index represents 4, so on. In this way we can minimize the size of the count array and also accomodate -ve numbers!!
    for (int i = 1; i < k; i++)
        count[i] += count[i - 1]; // cumulative sum to know how many eles are smaller than or equal to the current index i i.e, element(since this count array's index represents the eles).
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i] - min] - 1] = arr[i]; // putting the correct element in the output array in correct position maintaining the relative order thus ensuring stability(by iterating in reverse order!!);
        count[arr[i] - min]--;                    // Decrementing the count of the element as one of its elements is already placed in the sorted and correct position in the output array by the just above step!!
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i]; // copying the sorted correct order with stability to the main array!!
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int &x : arr)
        cin >> x;
    count_sort(arr, n);
    for (int &x : arr)
        cout << x << " ";
}