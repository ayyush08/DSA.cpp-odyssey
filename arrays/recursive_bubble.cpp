void bubbleSort(int arr[], int n) {
        if(n==0) return ;
        // Your code here
            for(int j=0;j<=n-2;j++){
                if(arr[j+1]<arr[j]){
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
            bubbleSort(arr,n-1);
    }

#include<iostream>
using namespace std;
int main()
{
    int s;
    cin >> s;
    int arr[s];
    for (int i = 0; i < s; i++)
    {
        cin >> arr[i];
    }
    bubbleSort(arr,s);
    for (int i = 0; i < s; i++)
    {
        cout << arr[i] << " ";
    }

return 0;
}