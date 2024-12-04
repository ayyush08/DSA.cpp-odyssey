void merge(int arr[], int l, int m, int r)
{
    // Your code here
    int temp[r + 1];
    int left = l;
    int right = m + 1;
    int k = 0;
    while (left <= m && right <= r)
    {
        if (arr[left] <= arr[right])
        {
            temp[k++] = arr[left];
            left++;
        }
        else
        {
            temp[k++] = arr[right];
            right++;
        }
    }
    while (left <= m)
    {
        temp[k++] = arr[left];
        left++;
    }
    while (right <= r)
    {
        temp[k++] = arr[right];
        right++;
    }
    for (int i = l; i <= r; i++)
    {
        arr[i] = temp[i - l];
    }
}

void mergeSort(int arr[], int l, int r)
{
    // code here
    if (l >= r)
        return;
    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
return 0;
}

// Time Complexity: O(nlogn) - because of the divide and conquer approach
// Space Complexity: O(n) - extra space is used for the temporary array