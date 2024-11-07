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

void heapifyDown(int i){
    int left = 2*i + 1;
    int right = 2*i + 2;
    int largest = i;
    if(left < heapSize && heap[left] > heap[largest]){
        largest = left;
    }
    if(right < heapSize && heap[right] > heap[largest]){
        largest = right;
    }
    if(largest != i){
        swap(heap[i], heap[largest]);
        heapifyDownD(largest);
    }
}
void deleteRoot(){
    if(heapSize == 0){
        cout<<"Heap is empty\n";
        return;
    }
    heap[0] = heap[heapSize-1];
    heapSize--;
    heapifyDown(0);
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
    deleteRoot();
    for(int i=0; i<heapSize; i++){
        cout<<heap[i]<<" ";
    }

return 0;
}