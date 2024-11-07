#include<bits/stdc++.h>
using namespace std;

#define MAX 1000

int heap[MAX];
int heapSize = 0;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}


void insert(int value){
    if(heapSize >= MAX){
        cout<<"Heap is full\n";
        return;
    }
    heap[heapSize] = value;
    int current = heapSize;
    heapSize++;


    while(current > 0 && heap[(current-1)/2] < heap[current]){
        swap(heap[(current-1)/2], heap[current]);
        current = (current-1)/2;
    }
}
int main()
{
    insert(10);
    insert(20);
    insert(5);
    insert(15);
    insert(30);
    for(int i=0; i<heapSize; i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
return 0;
}