#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low;
    int j = high;
    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
            i++;
        while (arr[j] > pivot && j >= low + 1)
            j--;
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
    // Your code here
}
void quickSort(int arr[], int low, int high)
{
    // code here
    if (low<high)
    {
        int parInd = partition(arr, low, high);
        quickSort(arr, low, parInd - 1);
        quickSort(arr, parInd + 1, high);
    }
}



int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
return 0;
}