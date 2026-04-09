
# Difference Array Technique (DAT) with Jumps

The Difference Array Technique (DAT) is traditionally used to perform O(1) range updates. However, in advanced competitive programming, you may encounter queries that require updating elements at specific intervals (jumps) within a range \[L,R\].

* * *

## 1\. Recap: Normal Difference Array

In a standard DAT, to add a value V to every element in the range \[L,R\]:

1.  Update: `diff[L] += V` and `diff[R + 1] -= V`.
    
2.  Prefix Sum: Compute the prefix sum of the `diff` array.
    
3.  Result: The prefix sum at index i gives the total value to be added to the original array at that index.
    

This works because the +V "starts" at L and is "cancelled out" by −V immediately after R.

* * *

## 2\. DAT with Jumps (K)

In this variation, you are given a jump value K. You only add V to indices L,L+K,L+2K,… as long as the index ≤R.

### The Challenge

We cannot use `diff[R + 1] -= V` because the updates are not contiguous. The "cancellation" must happen at the first index in the sequence that falls outside the range R.

### Step 1: Calculate the "Next" Index

To find where the sequence stops, we calculate the number of jumps possible within the range and find the first index that exceeds R.

*   Number of steps inside the range:
    
    steps\=(R-L)/K
    
*   Next index (The "Stop" point):
    
    next\_idx\=L+(steps+1)×K
    

### Step 2: Apply Updates

For each query (L,R,V,K):

1.  `diff[L] += V`
    
2.  `if (next_idx < n) diff[next_idx] -= V`
    

* * *

## 3\. Modified Cumulative Sum

Since the updates are spaced by K, the standard prefix sum (i−1) won't work. We must calculate the cumulative sum by looking back K indices.

Logic: For i from 0 to N−1: If i≥K: `diff[i] += diff[i - K]`

This ensures that the +V added at L only propagates to L+K,L+2K, etc., and is finally neutralized when it hits next\_idx.

* * *

## 4\. Handling Multiple K Values

If different queries have different K values, you cannot use a single `diff` array for all of them because the cumulative sum logic depends on K.

Strategy:

1.  Group Queries: Use a Map or a list of vectors to group all queries by their K value.
    
2.  Process per Group:
    
    *   For a specific K, create a fresh `diff` array.
        
    *   Apply all updates for that K.
        
    *   Compute the cumulative sum (using i−K).
        
    *   Add the results to the original `nums` array.
        
    *   Reset/Reuse the `diff` array for the next K.
        

* * *

## 5\. Variation: Range Product with Jumps

If the query asks to multiply every K\-th element by V instead of adding:

1.  Initial Value: Initialize the `diff` array with 1.
    
2.  Updates:
    
    *   `diff[L] *= V`
        
    *   `diff[next_idx] /= V` (Use modular inverse if working with primes).
        
3.  Cumulative Product:
    
    *   `diff[i] *= diff[i - K]`
        
4.  Apply to Array:
    
    *   `nums[i] *= diff[i]`
        

* * *

## 6\. Summary Table

| Feature | Normal DAT | DAT with Jumps (K) |
| --- | --- | --- |
| Step Size | 1 (Contiguous) | K (Periodic) |
| Stop Index | R+1 | L+(steps+1)×K |
| Prefix Logic | diff[i] += diff[i-1] | diff[i] += diff[i-K] |
| Complexity | O(Q+N) | O(Q+unique K×N) |