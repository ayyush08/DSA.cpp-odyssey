#include<bits/stdc++.h>
using namespace std;
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}
int main()
{
    int size;
    cout << "Enter size of array\n";
    cin >> size;
    int arr[size];
    cout << "Enter elements of array\n";
    for(int i=0;i<size;i++){
        cin >> arr[i];
    }
    selectionSort(arr,size);
    cout << "Sorted array is\n";
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
    return 0;
}