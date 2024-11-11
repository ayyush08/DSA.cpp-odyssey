// Heap Sorting an array in Ascending Order
// Approach - First create a Max heap for the given array elements, then delete the root element of the heap and store it in the last index of the array. Then heapify the remaining elements of the heap. Repeat this process until the heap size becomes 0.

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void createMaxHeap(vector<int> &nums, vector<int> &arr, int val)
    {
        arr.push_back(val);
        int size = arr.size();
        int i = size - 1;
        while (i != 0 && arr[(i - 1) / 2] < arr[i])
        {
            swap(arr[(i - 1) / 2], arr[i]);
            i = (i - 1) / 2;
        }
    }
    void del(vector<int> &arr, int size, int i)
    {
        int largest = i;
        while (true)
        {
            int leftChild = 2 * i + 1;
            int rightChild = 2 * i + 2;
            if (leftChild < size && arr[leftChild] > arr[largest])
                largest = leftChild;
            if (rightChild < size && arr[rightChild] > arr[largest])
                largest = rightChild;
            if (largest != i)
            {
                swap(arr[largest], arr[i]);
                i = largest;
            }
            else
            {
                break;
            }
        }
    }
    vector<int> sortArray(vector<int> &nums)
    {
        vector<int> arr;
        arr.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++)
        {
            createMaxHeap(nums, arr, nums[i]);
        }
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            swap(arr[0], arr[i]);
            del(arr, i, 0);
        }
        return arr;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {5,2,3,1};
    vector<int> res = sol.sortArray(nums);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}

// For descending order, create a Min heap and delete the root element of the heap and store it in the last index of the array. Then heapify the remaining elements of the heap. Repeat this process until the heap size becomes 0.