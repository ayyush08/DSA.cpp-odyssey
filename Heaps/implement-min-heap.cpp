// Implement Min Heap


// You need to implement the Min Heap with the following given methods.

// insert (x) -> insert value x to the min heap
// getMin -> Output the minimum value from min heap
// exctractMin -> Remove the minimum element from the heap
// heapSize -> return the current size of the heap
// isEmpty -> returns if heap is empty or not
// changeKey (ind, val) -> update the value at given index to val (index will be given 0-based indexing)
// initializeHeap -> Initialize the heap

// Examples:
// Input : operation = [ "initializeheap", "insert", "insert", "insert", "getMin", "heapSize", "isEmpty", "extractMin", "changeKey" , "getMin" ]
// nums = [ [4], [1], [10], [0, 16] ]
// Output : [ null, null, null, null, 1, 3, 0, null, null, 10 ]
// Explanation : In 1st operation we initialize the heap to empty heap.
// In 2nd, 3rd, 4th operation we insert 4, 1, 10 to the heap respectively. The heap after 4th operation will be -> [1, 4, 10].
// In 5th operation we output the minimum element from the heap i.e. 1.
// In 6th operation we output the size of the current heap i.e. 3.
// In 7th operation we output whether the heap is empty or not i.e. false (0).
// In 8th operation we remove the minimum element from heap. So the ne heap becomes -> [4, 10].
// In 9th operation we change the 0th index element to 16. So new heap becomes -> [16, 10]. After heapify -> [10, 16].
// In 10th operation we output the minimum element of the heap i.e. 10.

// Input : operation = [ "initializeheap", "insert", "insert", "extractMin", "getMin", "insert", "heapSize", "isEmpty", "extractMin", "changeKey" , "getMin" ]
// nums = [ [4], [1], [1], [0, 2] ]
// Output : [ null, null, null, null, 4, null, 2, 0, null, null, 2 ]
// Explanation : In 1st operation we initialize the heap to empty heap.
// In 2nd, 3rd operation we insert 4, 1 to the heap respectively. The heap after 4th operation will be -> [1, 4].
// In 4th operation we remove the minimum element from heap. So the ne heap becomes -> [4].
// In 5th operation we output the minimum element of the heap i.e. 4.
// In 6th operation we operation we insert 1 to the heap. The heap after 6th operation will be -> [1, 4].
// In 7th operation we output the size of the current heap i.e. 2.
// In 8th operation we output whether the heap is empty or not i.e. false (0).
// In 9th operation we remove the minimum element from heap. So the ne heap becomes -> [4].
// In 10th operation we change the 0th index element to 2. So new heap becomes -> [2].
// In 11th operation we output the minimum element of the heap i.e. 2.

// Constraints:
// 1 <= n <= 105
// -105 <= nums[i] <= 105

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<int>heap;
        int size;
        void heapifyUp(int i){
            int parent = (i-1)/2;
            if(i>0 && heap[parent]>heap[i]){
                swap(heap[i],heap[parent]);
                heapifyUp(parent);
            }
        }
        void heapifyDown(int i){
            int smallest = i;
            int leftChild = 2*i+1;
            int rightChild = 2*i+2;
            if(leftChild<size && heap[leftChild]<heap[smallest]) smallest=leftChild;
            if(rightChild<size && heap[rightChild]<heap[smallest]) smallest=rightChild;

            if(smallest!=i){
                swap(heap[smallest],heap[i]);
                heapifyDown(smallest);
            }
        }
        void initializeHeap(){
            heap.clear();
            size=0;
        }

        void insert(int key){
            heap.push_back(key);
            heapifyUp(size);
            size++;
        }

        void changeKey(int index, int new_val){
            if(heap[index]<new_val){
                heap[index]=new_val;
                heapifyDown(index);
            }
            else{
                heap[index]=new_val;
                heapifyUp(index);
            }
        }

        void extractMin(){
            // int mini = heap[0];
            swap(heap[0],heap[size-1]);
            size--;
            heapifyDown(0);
            heap.pop_back();
        }

        bool isEmpty(){
            return size==0;
        }

        int getMin(){
            return heap[0];
        }

        int heapSize(){
            return size;
        }
};