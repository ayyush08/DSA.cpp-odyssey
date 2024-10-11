#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for(int i=n-1;i>0;i--){
        bool swapped = false;
        for(int j=0;j<i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped) break;
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
    bubbleSort(arr, n);
    cout << "Sorted array is\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
return 0;
}