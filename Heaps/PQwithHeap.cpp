// Implement PQ using Heaps

// Implement a Priority Queue using heaps. It should have the following methods:
// PriorityQueue() initializes the PriorityQueue object
// push(val) inserts val into the priority queue
// pop() removes the element with the highest value
// top() returns the highest value element without removing it from the queue
// empty() returns 1 if the queue is empty else 0.
// Given input will always be valid.

// Example 1
// Input: [push(10), push(5), top(), pop(), top(), empty()]
// Output: [null, null, 10, null, 5, 0]

// Explanation:
// push(10): pushes 10 into the queue
// push(5): pushes 5 into the queue
// top(): returns 10 as the highest element in the queue
// pop(): removes 10
// top(): returns highest 5 as the highest element in queue
// empty(): returns 0 as queue is not empty.

// Example 2
// Input: [empty(), push(4), pop(), empty(), push(5), top()]
// Output: [1, null, null, 1, null, 5]
// Explanation:
// empty(): returns 1 as queue is empty
// push(4): pushes 4 into the queue
// pop(): removes 4
// empty(): returns 1 as queue is empty
// push(5): pushes 5 into the queue
// top(): returns 5 as the highest element in the queue
#include <bits/stdc++.h>
using namespace std;

class PriorityQueue
{
    vector<int> heap;
    int topEle;

public:
    PriorityQueue()
    {
        heap = {};
        topEle = -1;
    }

    void push(int val)
    {
        if (empty())
        {
            heap.push_back(val);
            return;
        }
        heap.push_back(val);
        int size = heap.size();
        int i = size - 1;
        while (i != 0 && heap[(i - 1) / 2] < heap[i])
        {
            swap(heap[(i - 1) / 2], heap[i]);
            i = (i - 1) / 2;
        }
    }

    void heapifyDown(int i)
    {
        if (empty())
            return;
        if (i > heap.size() - 1)
            return;
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        int largest = i;
        if (leftChild < heap.size() && heap[leftChild] > heap[largest])
        {
            largest = leftChild;
        }
        if (rightChild < heap.size() && heap[rightChild] > heap[largest])
        {
            largest = rightChild;
        }
        if (largest != i)
        {
            swap(heap[largest], heap[i]);
            heapifyDown(largest);
        }
    }
    void pop()
    {
        if (empty())
            return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int top()
    {
        return heap[0];
    }
    bool empty()
    {
        return heap.size() == 0;
    }
};

int main()
{
    PriorityQueue pq;
    pq.push(10);
    pq.push(5);
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
    cout << pq.empty() << endl;
    return 0;
}