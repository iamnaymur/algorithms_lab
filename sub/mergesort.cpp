#include <bits/stdc++.h>
using namespace std;

// Function to merge two sorted subarrays of arr[]
// First subarray is arr[low..mid]
// Second subarray is arr[mid+1..high]
void merge(int arr[], int low, int mid, int high)
{
    vector<int> temp;    // Temporary array to store merged result
    int left = low;      // Starting index of left subarray
    int right = mid + 1; // Starting index of right subarray

    // Merge the two sorted subarrays
    while (left <= mid && right <= high) // till I have element in both subarrays
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // Copy remaining elements from left subarray (if any)
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    // Copy remaining elements from right subarray (if any)
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy merged elements back into the original array
    for (int i = 0; i < temp.size(); i++)
        arr[low + i] = temp[i];
}

// Function to implement merge sort on arr[low..high]
void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);      // Recursively sort the left half
        mergeSort(arr, mid + 1, high); // Recursively sort the right half
        merge(arr, low, mid, high);    // Merge the sorted halves
    }
}

int main()
{
    int n;
    cin >> n; // Input number of elements

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i]; // Input array elements

    mergeSort(arr, 0, n - 1); // Call merge sort on the array

    // Output the sorted array
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
