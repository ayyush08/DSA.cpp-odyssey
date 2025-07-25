#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[],int n){
    if(n<=1) return;
    insertionSort(arr,n-1);
    int j=n-1;
    while(j>0&& arr[j-1]>arr[j]){
        swap(arr[j-1],arr[j]);
        j--;
    }
}
int main()
{
    int size;
    cin >> size;
    int arr[size];
    for(int i=0;i<size;i++){
        cin >> arr[i];
    }
    insertionSort(arr,size);
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
    
return 0;
}
