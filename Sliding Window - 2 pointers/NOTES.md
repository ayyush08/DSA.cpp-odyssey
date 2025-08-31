# Sliding Window - 2 Pointers

## Constant Window

### Max Sum Subarray of Size K

Given an array of integers and a number K, find the maximum sum of a subarray of size K.

**Approach:**
1. Calculate the sum of the first K elements.
2. Slide the window by removing the first element of the current window and adding the next element in the array.
3. Keep track of the maximum sum encountered.

**Code:**
```cpp
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int max_sum_subarray(const vector<int>& arr, int K) {
    int n = arr.size();
    if (n < K) return -1;  // Not enough elements

    // Calculate the sum of the first K elements
    int current_sum = accumulate(arr.begin(), arr.begin() + K, 0);
    int max_sum = current_sum;

    // Slide the window
    for (int i = K; i < n; ++i) {
        current_sum += arr[i] - arr[i - K];
        max_sum = max(max_sum, current_sum);
    }
    //Can also use while loop with l and r

    int l = 0, r = K - 1;
    current_sum = 0;
    max_sum = 0;

    while (r < n) {
        current_sum -= arr[l];
        l++;
        r++;
        current_sum += arr[r];
        max_sum = max(max_sum, current_sum);
    }

    return max_sum;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int K = 3;
    cout << "Max sum of subarray of size " << K << ": " << max_sum_subarray(arr, K) << endl;
    return 0;
}
```

## Longest Subarray or Substring with a condition (Mostly asked pattern)

### Longest Subarray with sum <= k

1. Brute Force Template - generate all subarrays and check with the condition

- Time Complexity: O(n^2)
- Space Complexity: O(1)

```cpp
for (int i = 0; i < n; i++) {
    int subarray_sum = 0;
    for (int j = i; j < n; j++) {
        subarray_sum += arr[j];
        if (subarray_sum <= k) {
            max_length = max(max_length, j - i + 1);
        }
    }
}
```

2. Better Template - use 2 pointer and sliding window.


- Start with window [l, r]
- Expand r to include more elements (Expand for r)
- Contract l to remove elements from the left(Shrink for l)
- Maintain the sum and check the condition

- Time Complexity: O(2n)
- Space Complexity: O(1)

```cpp
int l = 0, r = 0;
int current_sum = 0;
int max_length = 0;

while (r < n) {
    current_sum += arr[r];
    while (current_sum > k) {
        current_sum -= arr[l];
        l++;
    }
    if(current_sum <= k)
    max_length = max(max_length, r - l + 1);
    r++;
}
```

3. Optimal - Trim down the shrinking causing extra O(N)

- Why to shrink if we are asked only the length and not the actual subarray?
- We can keep track of the maximum length without needing to shrink the window.

- Time Complexity: O(n)
- Space Complexity: O(1)

```cpp
int l = 0, r = 0;
int current_sum = 0;
int max_length = 0;

while (r < n) {
    current_sum += arr[r];
    if (current_sum > k) {
        current_sum -= arr[l];
        l++;
    }
    if(current_sum <= k)
    max_length = max(max_length, r - l + 1);
    r++;
}
```

NOTE: To print the subarray we have to go back to while loop method

## Number of Subarrays/Substring with some condition

- will be solved using pattern 2

### Find number of subarrays with sum == k

Since its a constant condition so we don't know when to shrink/expand the window.

- We utilise previous patter in a smart way

1. Find number of subarrays with sum <= k (let's say X)
2. Find number of subarrays with sum <= k-1 (let's say Y)
3. The result will be X - Y


## Finding shortest window length with some condition

- For a valid window [l, r], we look for minimum size by try to shrink and keep check if that shrinked window is valid or not and store the shortest shrinked window as the answer