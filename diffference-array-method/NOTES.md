# Difference Array Method
The Difference Array Method is a technique used to efficiently perform range update operations on an array. Instead of updating each element in the specified range directly, we use a difference array to keep track of the changes, allowing for faster updates and queries.

## How It Works
1. **Initialization**: Create a difference array `D` of the same length as the original array `A`, initialized to zero.
2. **Range Update**: To add a value `val` to all elements in the range `[l, r]` of the original array:
   - Increment `D[l]` by `val`.
   - Decrement `D[r + 1]` by `val` (if `r + 1` is within bounds).

3. **Prefix Sum**: To get the final values in the original array, compute the prefix sum of the difference array `D`. The value at each index `i` in the original array can be obtained by adding the prefix sum up to `i` to the original value at `i`.

## Example
Consider an original array `A = [0, 0, 0, 0, 0]` and we want to perform the following range updates:
1. Add `5` to the range `[1, 3]`
2. Add `10` to the range `[2, 4]`
- After the first update, the difference array `D` becomes `[0, 5, 0, 0, -5, 0]`.
- After the second update, the difference array `D` becomes `[0, 5, 10, 0, -5, -10]`.
- To get the final array, compute the prefix sum of `D`:
  - Index 0: `0`
  - Index 1: `0 + 5 = 5`
  - Index 2: `5 + 10 = 15`
  - Index 3: `15 + 0 = 15`
  - Index 4: `15 - 5 = 10`
The final array after all updates is `A = [0, 5, 15, 15, 10]`.

## Advantages
- **Efficiency**: The difference array method allows for O(1) time complexity for range updates, making it significantly faster than updating each element individually.
- **Simplicity**: The method is straightforward to implement and understand, making it a useful technique for problems involving multiple range updates.


## Difference array for 2-D arrays
Suppose we have a query with [r1,c1,r2,c2] and we want to add val to all elements in the submatrix defined by the corners (r1,c1) and (r2,c2). We can use a 2-D difference array D to perform this operation efficiently.

Simple iterate from r1 to r2 inclusive:
- add val to D[i][c1]
- subtract val from D[i][c2 + 1] (if c2 + 1 is within bounds)

After processing all queries, we can compute the final values in the original 2-D array by calculating the prefix sums for each row of the difference array D.
