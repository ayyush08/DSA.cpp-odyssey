#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n){
    for(int i=0;i<n;i++){
        int j=i;
        while(j>0&&arr[j-1]>arr[j]){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
}

int main()
{
    int n;
    cout << "Enter size of array\n";
    cin >> n;
    int arr[n];
    cout << "Enter elements of array\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    insertionSort(arr, n);
    cout << "Sorted array is\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
return 0;
}

// Time Complexity: O(n^2) - because of the nested loops
// Space Complexity: O(1) - no extra space is used