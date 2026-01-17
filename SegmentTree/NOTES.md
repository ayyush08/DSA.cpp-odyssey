# Segment Tree – Concepts & Build (Part 1)

## What is a Segment Tree?
A **Segment Tree** is an efficient data structure used to perform **range-based queries** and **updates** on an array.

It is mainly used when:
- Multiple queries are asked
- Each query involves a **range [L, R]**
- Array size and number of queries are large

---

## When to Think of Segment Tree?
Think of a Segment Tree when a problem involves:
- Range Sum Query
- Range Minimum / Maximum Query
- Range Product
- Range Average
- Range Updates

If a problem repeatedly asks:
> "Given L and R, find something in this range"

Segment Tree should click immediately.

---

## Problem with Naive Approach
For each query, iterating from `L` to `R` takes:

Time = O(N) per query
Total Time = O(Q × N)


This becomes too slow for large `N` and `Q`.

---

## Why Prefix Sum is Not Enough
Prefix Sum works only for:
- Range Sum Queries

Prefix Sum **cannot handle**:
- Range Min / Max
- Range Product
- Efficient Updates

Segment Tree handles all these cases efficiently.

---

## Core Idea of Segment Tree
- Segment Tree is a **Binary Tree**
- Each node represents a **segment (interval)** of the array
- Each node stores information about its range (sum, min, max, etc.)

---

## Types of Nodes

### Root Node
- Represents the entire array
- Range: `[0, N-1]`

### Leaf Nodes
- Represent a single element
- Range: `[i, i]`

### Internal Nodes
- Represent subranges
- Combine results of their children

---

## How Segment Tree is Built

For a node representing range `[L, R]`:
1. Compute mid:
    `mid = (L + R) / 2`

2. Split range into:
- Left child → `[L, mid]`
- Right child → `[mid + 1, R]`
3. Repeat until `L == R`

---

## Base Case
When: `L == R`
- Node becomes a leaf
- Stores the value of the array at index `L`

---

## Important Properties

### Binary Tree
- Every non-leaf node has **exactly two children**

### Balanced Tree
- Height difference between left and right subtree is at most 1

### Height

- Height of Segment Tree = O(log N)


---

## Number of Nodes in Segment Tree
- Leaf nodes = `N`
- Internal nodes = `N - 1`

Total nodes: = `2N - 1`

For Safety: Segment Tree size = `2*N`


---

## Array Representation
Segment Tree is stored using an array.

If a node is at index `i`:
- Left child → `2*i + 1`
- Right child → `2*i + 2`

Root is always at index `0`.

---

## Building Segment Tree (Range Sum Example)

```cpp
build(index, L, R):
if L == R:
tree[index] = arr[L]
return

mid = (L + R) / 2
build(2*index + 1, L, mid)
build(2*index + 2, mid + 1, R)

tree[index] = tree[2*index + 1] + tree[2*index + 2]
```


---

## Recursion Insight (Leap of Faith)
- Left subtree is built completely
- Right subtree is built completely
- Parent node combines results

This follows **Divide and Conquer**.

---

## Time & Space Complexity

### Build Time
- O(N)

### Space Complexity
- O(N) for tree
- O(log N) for recursion stack


---

## Why Segment Tree is Powerful
- Handles large inputs efficiently
- Supports multiple query types
- Allows fast updates
- Much faster than brute force



# Segment Tree – Update Query

## Problem with Prefix Sum During Updates

Prefix Sum allows:
- Range Sum Query in `O(1)`

But fails when **updates** occur.

### Example
If: arr = [3,1,2,7]
Prefix Sum = [3,4,6,13]

Now update: arr[1] = 4


Prefix sum becomes invalid and must be recomputed:
Prefix Sum = [3,7,9,16]


### Time Complexity
- Updating prefix sum takes `O(N)`
- Multiple updates → very slow ❌

---

## Need for Segment Tree
We need a data structure that supports:
- Range Sum Queries
- Point Updates
- Both efficiently

➡️ **Segment Tree solves this**

---

## What is an Update Query?
An **Update Query** means: Update index idx to new value

Example: Update index 1 to value 2:

This affects:
- The leaf node representing index `1`
- All its ancestor nodes in the Segment Tree

---

## How Update Works in Segment Tree

### Key Idea
- Start from the **root**
- Decide whether to go **left or right**
- Reach the **leaf node**
- Update value
- Recalculate values while returning back

---

## Update Traversal Logic

At a node representing range `[L, R]`:
1. Compute: `mid = (L + R) / 2`
2. If `idx <= mid`, go to left child
3. Else, go to right child


---

## Base Case (Leaf Node)
When:
`L == R == idx`
- Update the leaf node value to `new_value`

- This node represents exactly `idx`
- Update:
`tree[index] = new_value`

- Return

---

## Updating Ancestors
While returning from recursion: 
`tree[index] = tree[2*index + 1] + tree[2*index + 2]`


This keeps the Segment Tree consistent.

---

## Update Function (Range Sum)
```cpp
void update(int index, int L, int R, int idx, int new_value) {
    if (L == R) {
        tree[index] = new_value;
        return;
    }
    int mid = (L + R) / 2;
    if (idx <= mid) {
        update(2*index + 1, L, mid, idx, new_value);
    } else {
        update(2*index + 2, mid + 1, R, idx, new_value);
    }
    tree[index] = tree[2*index + 1] + tree[2*index + 2];
}
```


---

## Why Update is Efficient

- Only one path from root to leaf is traversed
- Number of visited nodes = height of tree

### Height of Segment Tree
- O(log N)

### Update Time Complexity
- O(log N) per update
Much faster than O(N) in prefix sum!


---

## What Gets Updated?
Only:
- The leaf node corresponding to `idx`
- Its ancestors

Not the entire tree.

---

## Comparison Summary

| Operation        | Prefix Sum | Segment Tree |
|------------------|------------|--------------|
| Range Sum Query  | O(1)       | O(log N)     |
| Point Update     | O(N)       | O(log N)     |
| Range Min / Max  | ❌         | ✅           |

---

# Segment Tree – Range Sum Query 


## Problem Statement
Given an array `nums`, answer queries of the form:

> "Find sum of elements from index start to end"


Example queries:
- Sum from index `2` to `4`
- Sum from index `1` to `5`
- Sum from index `2` to `6`

---

## Why Not Brute Force?
For each query:
- Iterate from `start` to `end`
- Compute sum

### Time Complexity
- O(N) per query
- O(Q × N) for Q queries


This is too slow for large inputs.

---

## Solution: Segment Tree
We use the already-built Segment Tree to answer range sum queries efficiently.

---

## Query Strategy
We start from the **root node** and recursively decide:

At each node representing range `[L, R]`, compare it with query range `[start, end]`.

There are **three possible cases**.

---

## Case 1: Completely Outside Range (No Overlap)

### Condition
 `L> end` or `R < start`


### Meaning
- The node's range lies completely outside the query range
- This node contributes nothing to the sum

### Action
- Return `0` (neutral element for sum)


---

## Case 2: Completely Inside Range (Total Overlap)

### Condition
  `L >= start` and `R <= end`

  
### Meaning
- The node’s range lies completely inside the query range

### Action
- Return `tree[index]` (the sum stored at this node)


No need to go deeper.

---

## Case 3: Partial Overlap

### Meaning
- Part of the node’s range is inside the query
- Part is outside

### Action
- Go to both children
- Combine their results

- Return: leftQuery + rightQuery


---

## Recursive Query Function (Range Sum)

```cpp
int query(int index, int L, int R, int start, int end) {
    // Case 1: No Overlap
    if (R < start || L > end) {
        return 0; // neutral element
    }
    // Case 2: Total Overlap
    if (L >= start && R <= end) {
        return tree[index];
    }
    // Case 3: Partial Overlap
    int mid = (L + R) / 2;
    int leftSum = query(2*index + 1, L, mid, start, end);
    int rightSum = query(2*index + 2, mid + 1, R, start, end);
    return leftSum + rightSum;
}
```


---

## Example Walkthrough
Query:
Sum from  index `2` to `6`


What happens:
- Root splits the query into left and right
- Some nodes are skipped (out of range)
- Some nodes return stored sums directly
- Some nodes recurse further
- Final result is combined from multiple nodes

Final Answer:
14


---

## Why This is Efficient

### Key Observation
- We do **not visit all nodes**
- We only traverse relevant branches

### Tree Height
- O(log N)


### Worst Case
- Traverse two paths (start & end) : 2 × O(log N) = O(log N)


---

## Time Complexity

### Range Sum Query
- O(log N) per query


### Compared to Brute Force
| Method         | Time per Query |
|----------------|---------------|
| Brute Force    | O(N)          |
| Segment Tree   | O(log N)      |

Massive improvement 🚀


---

## Final Takeaway
- Segment Tree supports:
  - Build → `O(N)`
  - Update → `O(log N)`
  - Query → `O(log N)`
- One data structure solves multiple problems efficiently
- Same logic applies to sum, min, max, product queries


# Segment Tree – Why Array Size = 4 × N 

a **very common doubt**:

> ❓ Why do we usually take **segment tree array size = 4 × N**?

---

## Observation from Practice
Many people face:
- **Array index out of bound** errors  
when they allocate segment tree size as `2*N - 1`

So the question is:
👉 Why is `2*N - 1` not always safe?

---

## Case 1: When `N` is a Power of Two

Example:
N = 8

### Leaf Nodes 
- 8 leaf nodes

### Internal Nodes
- 4+2+1 = 7 internal nodes

### Total Nodes
- 8 + 7 = 15 nodes = 2*N - 1 = 15


✔ Works perfectly  
✔ All nodes pair cleanly  
✔ No extra nodes needed  

Same for:
- `N = 4 → 7 nodes`
- `N = 16 → 31 nodes`

---

## Key Pattern (Power of Two Case)

If:
N = 2^k (power of two)

Then:
Total nodes = 2*N - 1

This is the **ideal case**.

---

## Case 2: When `N` is NOT a Power of Two

Example:
N = 10

### Leaf Nodes
- 10 leaf nodes

### Pairing Problem
- First level: 10 → 5 nodes
- Next level: 5 cannot pair evenly ❌
- One node is left unpaired

👉 Tree becomes **unbalanced**
👉 Indexing breaks
👉 Array overflow happens

---

## Solution: Pad to Next Power of Two

For safe construction:
- Find the **next power of two ≥ N**
- Add **dummy leaf nodes** until size matches

### Examples

| Original N | Next Power of Two |
|-----------:|------------------:|
| 9          | 16 |
| 10         | 16 |
| 17         | 32 |

---

## Leaf Node Count After Padding

If `N` is not power of two:
- Leaf nodes ≈ `2*N` (approximately)

Example:
N = 9
→ next power of two = 16


---

## Total Nodes Calculation

Levels of the tree after padding:


Level 0: 2N
Level 1: N
Level 2: N/2
Level 3: N/4
...


This forms a **Geometric Progression**:

2N + N + N/2 + N/4 + ... = 4N - 1 (approximately)


### Sum of GP
Sum = 2N / (1 - 1/2)
= 4N



---

## Final Conclusion

### Safe Segment Tree Size
Segment Tree Array Size = 4 × N



✔ Works for all cases  
✔ Avoids index out of bound  
✔ Interview-safe answer  

---

## Interview Explanation (Short Version)

- If `N` is power of two → nodes = `2N - 1`
- If `N` is not power of two:
  - We pad to next power of two
  - Leaf nodes ≈ `2N`
  - Total nodes ≈ `4N`
- Hence, we allocate `4*N` to be safe

---

## Why Everyone Uses `4*N`

- Simpler than calculating next power of two
- Guaranteed no overflow
- Accepted standard in interviews & platforms

---

## Key Takeaways
- `2*N - 1` is **not always safe**
- Padding is required when `N` is not power of two
- `4*N` is a **safe upper bound**
- Always use `vector<int> segTree(4*N)`

---

