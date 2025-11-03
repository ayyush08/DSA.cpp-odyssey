# Almost-complete binary tree

A binary tree (each node has at most two children) is called an almost-complete binary tree when:

- Every level except the last is completely filled.
- The last level is filled from left to right with no gaps between nodes.

In other words, all nodes are as far left as possible on the last level.

Why it matters:

- Heaps are typically implemented as almost-complete binary trees, which lets them be stored compactly in an array and ensures the tree height is O(log n).
- The left-to-right filling property preserves a predictable structure for insertion and deletion.

# Heap

A heap is a special tree-based data structure that satisfies the heap property. It is commonly used to efficiently solve problems involving priority and to implement algorithms like sorting and finding the smallest or largest elements.

## Heap Property
The heap property defines the relationship between a parent node and its child nodes in a heap. This property ensures that the structure of the heap remains consistent for efficient operations. The exact nature of this relationship depends on the type of heap. There are two types of heaps:
- **Min-Heap**: The value of each parent node must be less than or equal to the values of its child nodes. This ensures that the smallest element is always at the root of the heap.
- **Max-Heap**: The value of each parent node must be greater than or equal to the values of its child nodes. This ensures that the largest element is always at the root of the heap.

## How to store an almost-complete binary tree in an array

- root at index 0
- left child of node at index i is at index 2i + 1
- right child of node at index i is at index 2i + 2
- parent of node at index i is at index ceil(i/2)-1

NOTE: Not using an Almost Complete Binary Tree to implement a heap will lead to inefficient space usage and slower operations, as the predictable structure of the tree is lost.

## Number of Internal Nodes 
No. of leaf nodes - 1

## Indices of Leaf Nodes 
floor(n/2) to n-1 where n is the total number of nodes in the heap

## Indices of Internal Nodes
0 to floor(n/2)-1 where n is the total number of nodes in the heap


# Heapify Algorithm

## Heapify-down - when  we decrease a node's value (say in Max-Heap)


The algorithm is used to maintain the max-heap property in a binary tree. It is typically called when a node's value has been decreased, and we need to ensure that the subtree rooted at that node satisfies the max-heap property.

Steps:
1. Start with a node at index i.
2. Compare the value of the node with its left and right children.
3. If the value of the node is less than either of its children, swap it with the larger child.
4. Recursively call Max-Heapify on the child node that was swapped.


## Heapify-up - when we increase a node's value (say in Max-Heap)

The algorithm is used to maintain the max-heap property in a binary tree. It is typically called when a node's value has been increased, and we need to ensure that the subtree rooted at that node satisfies the max-heap property.

Steps:
1. Start with a node at index i.
2. Compare the value of the node with its parent.
3. If the value of the node is greater than its parent, swap it with the parent.
4. Recursively call Max-Heapify on the parent node that was swapped.


##  Psuedo-code

```cpp
void func(arr,ind,val){
    if(arr[ind]<val){
        arr[ind]=val
        heapify-up(arr,ind)
    }
    else if(arr[ind]>val){
        arr[ind]=val
        heapify-down(arr,ind)
    }
}

void heapify-down(arr,ind){
    largest=ind
    leftChild = 2*ind + 1
    rightChild = 2*ind + 2
    if(leftChild < arr.length and arr[leftChild] > arr[largest]){
        largest = leftChild
    }
    if(rightChild < arr.length and arr[rightChild] > arr[largest]){
        largest = rightChild
    }
    if(largest != ind){
        swap(arr[ind], arr[largest])
        heapify-down(arr, largest)
    }
}

void heapify-up(arr,ind){
    parent = (ind-1)/2
    if(ind>0 && arr[ind] > arr[parent]){
        swap(arr[ind], arr[parent])
        heapify-up(arr, parent)
    }
}

```

- Time Complexity: Both heapify-up and heapify-down take O(log n) time, where n is the number of nodes in the heap.
- Space Complexity: O(1) for iterative implementation, O(log n) for recursive implementation due to call stack.

NOTE: Above Psuedo-code works for Max-Heap. For Min-Heap, just change the comparison operators accordingly.