# Segment Tree: Range Minimum/Maximum Queries with Lazy Propagation

## Overview
This tutorial covers how to efficiently handle **mutable range min/max queries** using Segment Tree with Lazy Propagation.

**Video Reference**: Video #14 in Segment Tree Concepts & Questions playlist

---

## Problem Statement

Given an array, you need to handle two types of queries efficiently:
1. **Range Query**: Find the minimum and/or maximum element in a given range `[L, R]`
2. **Range Update**: Add a value to all elements in a range `[start, end]`

**Example**:
- Array: `[1, 2, 4, 3]`
- Query: Find min/max in range `[1, 3]`
- Update: Add `+1` to all elements in range `[0, 3]` → Array becomes `[2, 3, 5, 4]`

**Naive Approach**: O(Q × N) - Iterate through range for each query (NOT ACCEPTABLE)

**Optimized Approach**: O(Q × log N) - Using Segment Tree with Lazy Propagation

---

## Prerequisites

**⚠️ IMPORTANT**: You MUST understand Lazy Propagation before proceeding with this topic.
- Understand basic Segment Tree operations
- Know how lazy propagation works for range updates

---

## Data Structures Required

We need **three arrays**, each of size `4 × n`:

### 1. `segmentMin[i]`
- **Definition**: Stores the minimum value in the range represented by the i-th node
- **Usage**: To quickly retrieve minimum value for any range query

### 2. `segmentMax[i]`
- **Definition**: Stores the maximum value in the range represented by the i-th node  
- **Usage**: To quickly retrieve maximum value for any range query

### 3. `lazy[i]`
- **Definition**: Stores the pending value to be propagated to children of the i-th node
- **Usage**: For lazy propagation - delays updates to children nodes

**Alternative Approach**: Instead of three separate arrays, you can create a `struct Node` containing `{min, max}` and have one segment tree array of this struct type.

---

## Segment Tree Structure Review

```
           [0-3]          <- Root node (i=0), represents range [0,3]
          /      \
      [0-1]      [2-3]    <- i=1 and i=2
      /  \       /   \
   [0]  [1]   [2]  [3]    <- Leaf nodes
```

**Node Indexing**:
- Root: `i = 0`
- Left child of i: `2i + 1`
- Right child of i: `2i + 2`
- Parent of i: `(i-1) / 2`

**Range Representation**:
- Each node represents a range `[L, R]`
- Root represents entire array `[0, n-1]`
- Leaf nodes represent single elements

---

## Building the Segment Tree

### Example: Array `[1, 2, 4, 3]`

**Leaf Nodes** (single elements):
- Node at index 0: `min=1, max=1` (represents arr[0])
- Node at index 1: `min=2, max=2` (represents arr[1])
- Node at index 2: `min=4, max=4` (represents arr[2])
- Node at index 3: `min=3, max=3` (represents arr[3])

**Internal Nodes** (computed from children):
- Node representing range [2,3]: 
  - `min = min(4, 3) = 3`
  - `max = max(4, 3) = 4`
  
- Node representing range [0,1]:
  - `min = min(1, 2) = 1`
  - `max = max(1, 2) = 2`
  
- Root node representing range [0,3]:
  - `min = min(1, 3) = 1`
  - `max = max(2, 4) = 4`

**How to compute**:
- Ask left child: "What's your minimum?"
- Ask right child: "What's your minimum?"
- Take minimum of both for current node's minimum
- Same process for maximum

---

## Core Functions

### 1. `updateRange(start, end, val, i, L, R)`

**Purpose**: Update all elements in range `[start, end]` by adding `val`

**Parameters**:
- `start, end`: Query range to update
- `val`: Value to add to the range
- `i`: Current node index (start with 0)
- `L, R`: Range represented by current node (start with [0, n-1])

**Algorithm**:

```cpp
void updateRange(int start, int end, int val, int i, int L, int R) {
    // STEP 1: Check if current node has pending lazy updates
    if (lazy[i] != 0) {
        propagate(i, L, R);
    }
    
    // STEP 2: No overlap - query range is outside current node's range
    if (start > R || end < L) {
        return;  // Nothing to update
    }
    
    // STEP 3: Complete overlap - current node's range [L,R] is fully inside [start,end]
    if (L >= start && R <= end) {
        lazy[i] += val;           // Mark this node for lazy update
        propagate(i, L, R);       // Propagate to children
        return;                    // Optimization: Don't go further down
    }
    
    // STEP 4: Partial overlap - need to go to children
    int mid = (L + R) / 2;
    
    // Recursively update left child
    updateRange(start, end, val, 2*i + 1, L, mid);
    
    // Recursively update right child
    updateRange(start, end, val, 2*i + 2, mid + 1, R);
    
    // STEP 5: Update current node using children's values
    segmentMin[i] = min(segmentMin[2*i + 1], segmentMin[2*i + 2]);
    segmentMax[i] = max(segmentMax[2*i + 1], segmentMax[2*i + 2]);
}
```

**Three Cases**:

1. **No Overlap**: `start > R || end < L`
   - Query range doesn't intersect with current node's range
   - Simply return, nothing to update

2. **Complete Overlap**: `L >= start && R <= end`
   - Current node's entire range is within query range
   - Update lazy[i], propagate to children, and return
   - **This is the optimization** - we don't traverse all the way down!

3. **Partial Overlap**: 
   - Need to check both children
   - Recursively update left and right subtrees
   - Update current node based on children's updated values

---

### 2. `propagate(i, L, R)`

**Purpose**: Apply pending lazy updates to current node and push them to children

**Parameters**:
- `i`: Current node index
- `L, R`: Range represented by current node

**Algorithm**:

```cpp
void propagate(int i, int L, int R) {
    // Only propagate if there's a pending update
    if (lazy[i] != 0) {
        // Update current node's min and max
        segmentMin[i] += lazy[i];
        segmentMax[i] += lazy[i];
        
        // If not a leaf node, propagate to children
        if (L != R) {  // L == R means leaf node
            lazy[2*i + 1] += lazy[i];  // Push to left child
            lazy[2*i + 2] += lazy[i];  // Push to right child
        }
        
        // Clear current node's lazy value
        lazy[i] = 0;
    }
}
```

**Key Points**:
- Update min/max of current node by adding lazy[i]
- If not a leaf (L != R), pass the lazy value to both children
- DON'T actually update the children now - just mark them in their lazy array
- Clear lazy[i] = 0 after done

**Why Lazy Propagation?**
- Without lazy propagation: Would need to traverse all nodes in the range - O(N)
- With lazy propagation: Stop at nodes that fully cover the range - O(log N)
- Children will be updated when we visit them in the future

---

## Example Walkthrough

### Initial Setup
**Array**: `[1, 2, 4, 3]`

**Segment Tree**:
```
                [0-3]: min=1, max=4
               /                    \
        [0-1]: min=1, max=2      [2-3]: min=3, max=4
        /           \             /           \
   [0]: min=1    [1]: min=2    [2]: min=4    [3]: min=3
```

### Query: Add +1 to range [0, 3]

**Step 1**: Start at root (i=0, range [0,3])
- Query: [0,3], Node range: [0,3]
- **Complete overlap!** (0 >= 0 && 3 <= 3)
- `lazy[0] += 1` → `lazy[0] = 1`

**Step 2**: Call propagate(0, 0, 3)
- `segmentMin[0] += 1` → becomes 2
- `segmentMax[0] += 1` → becomes 5
- Not a leaf, so push to children:
  - `lazy[1] += 1` → `lazy[1] = 1`
  - `lazy[2] += 1` → `lazy[2] = 1`
- `lazy[0] = 0` (clear)

**Result**:
- Root is updated immediately: min=2, max=5 ✓
- Children have lazy updates pending (lazy[1]=1, lazy[2]=1)
- When we visit children later, they'll be updated
- We didn't traverse all the way to leaf nodes! (Optimization)

---

## Time Complexity Analysis

| Operation | Time Complexity |
|-----------|----------------|
| Build Tree | O(N) |
| Range Update | O(log N) |
| Range Query (Min/Max) | O(log N) |
| Overall for Q queries | O(Q × log N) |

**Space Complexity**: O(4N) = O(N) for three segment tree arrays

---

## Key Observations

### Why 4 × N size?
- Segment tree needs at most 4N space for N elements
- This ensures no overflow for any tree structure
- Refer to dedicated video on why 4N size is required

### How Lazy Propagation Helps
1. **Without Lazy Propagation**:
   - Update range [0,3] in array of size 1000
   - Would need to update all nodes covering this range
   - Could be O(N) updates

2. **With Lazy Propagation**:
   - Stop at nodes that completely cover the query range
   - Mark them with lazy values
   - Update only a few nodes immediately - O(log N)
   - Children updated lazily when visited

### Leaf Node Detection
- A node is a leaf when `L == R`
- Leaf nodes don't have children
- Check `if (L != R)` before accessing children

---

## Complete Implementation Template

```cpp
class SegmentTree {
private:
    vector<int> segmentMin;
    vector<int> segmentMax;
    vector<int> lazy;
    int n;
    
    void propagate(int i, int L, int R) {
        if (lazy[i] != 0) {
            segmentMin[i] += lazy[i];
            segmentMax[i] += lazy[i];
            
            if (L != R) {
                lazy[2*i + 1] += lazy[i];
                lazy[2*i + 2] += lazy[i];
            }
            
            lazy[i] = 0;
        }
    }
    
    void updateRange(int start, int end, int val, int i, int L, int R) {
        // Check for pending updates
        if (lazy[i] != 0) {
            propagate(i, L, R);
        }
        
        // No overlap
        if (start > R || end < L) {
            return;
        }
        
        // Complete overlap
        if (L >= start && R <= end) {
            lazy[i] += val;
            propagate(i, L, R);
            return;
        }
        
        // Partial overlap
        int mid = (L + R) / 2;
        updateRange(start, end, val, 2*i + 1, L, mid);
        updateRange(start, end, val, 2*i + 2, mid + 1, R);
        
        // Update current node from children
        segmentMin[i] = min(segmentMin[2*i + 1], segmentMin[2*i + 2]);
        segmentMax[i] = max(segmentMax[2*i + 1], segmentMax[2*i + 2]);
    }
    
public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        segmentMin.resize(4 * n);
        segmentMax.resize(4 * n);
        lazy.resize(4 * n, 0);
        // Build tree here...
    }
    
    void update(int start, int end, int val) {
        updateRange(start, end, val, 0, 0, n - 1);
    }
};
```

---

## Common Mistakes to Avoid

1. **Forgetting to check lazy[i]** at the start of updateRange
2. **Not clearing lazy[i]** after propagation
3. **Accessing children of leaf nodes** (always check L != R)
4. **Wrong child indices** (remember: left = 2i+1, right = 2i+2)
5. **Not updating parent from children** after recursive calls

---


## Summary


✅ **Key Takeaway**: 
Lazy Propagation allows us to handle range updates in O(log N) time by deferring updates to children nodes until absolutely necessary.

✅ **Time Complexity**: O(Q × log N) for Q queries

✅ **Next Step**: Practice with POTD and similar problems!

---
