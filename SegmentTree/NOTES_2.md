# Segment Tree – Range Minimum Query (RMQ)

## Motivation
- Brute force RMQ takes **O(N)** per query.
- With multiple queries, total time becomes **O(Q × N)** → too slow.
- Segment Tree reduces each query to **O(log N)**.

---

## What is RMQ?
Given:
- An array `arr` of size `N`
- Multiple queries `(L, R)`

Task:
> Find the **minimum element** in the subarray `[L, R]` (0-based indexing).

---

## Core Idea of Segment Tree
- Each node represents a **range [L, R]**
- Leaf nodes represent **single elements**
- Internal nodes store: **min(left_child, right_child)**


---

## Segment Tree Representation
- Stored using an array
- Root index = `0`
- Left child = `2*i + 1`
- Right child = `2*i + 2`
- **Safe size:** `4 * N`

---

## Building the Segment Tree

### Logic
1. If `L == R` → leaf node  
 Store `arr[L]`
2. Otherwise:
 - Split range using `mid`
 - Build left & right subtree
 - Store minimum of both children

### Pseudocode
```cpp
build(i, L, R):
  if L == R:
      tree[i] = arr[L]
      return
  mid = (L + R) / 2
  build(2*i+1, L, mid)
  build(2*i+2, mid+1, R)
  tree[i] = min(tree[2*i+1], tree[2*i+2])
```

---
## Querying RMQ

### Logic
Three Cases:

| Case | Condition | Action |
|------|-----------|--------|
| **No overlap** | Query range doesn't intersect [L, R] | Return `INT_MAX` |
| **Complete overlap** | Query range completely covers [L, R] | Return `tree[i]` |
| **Partial overlap** | Query range partially overlaps [L, R] | Return `min(left_query, right_query)` |

### Pseudocode
```cpp
query(i, L, R, QL, QR):
  if QR < L or QL > R:           // No overlap
      return INT_MAX
  if QL <= L and R <= QR:        // Complete overlap
      return tree[i]
  mid = (L + R) / 2
  left_min = query(2*i+1, L, mid, QL, QR)
  right_min = query(2*i+2, mid+1, R, QL, QR)
  return min(left_min, right_min)
```

### Why INT_MAX for No Overlap?
- We are calculating minimum
- INT_MAX never affects the result of min(a, INT_MAX)
- Acts as a neutral element

## Time & Space Complexity

| Operation | Complexity |
|-----------|-----------|
| Build | O(N) |
| Query | O(log N) per query |
| Total | O(Q log N) |
| Space | O(4N) |

---

## Comparison with Range Sum Query

| Feature | Range Sum | RMQ |
|---------|-----------|-----|
| Merge Operation | `+` | `min()` |
| No Overlap Return | `0` | `INT_MAX` |
| Time Complexity | O(log N) | O(log N) |

---

## Interview Tips

- Always explain overlap cases
- Mention why 4*N space is safe
- Highlight difference between sum vs min
- Emphasize log N traversal height

# Segment Tree – Lazy Propagation (Range Update + Range Query)

## Motivation
- **Point Update**: Update a single index → `O(log N)`
- **Range Update (naive)**:  
  Update every index in `[L, R]` using point update  
  ⛔ Time = `O(N log N)` (too slow)

👉 We need a faster way to update **entire ranges** efficiently.

---

## What is Lazy Propagation?
Lazy Propagation is an **optimization technique** for Segment Trees that allows:

- **Range updates** in `O(log N)`
- Without immediately updating all child nodes
- Updates are **postponed** and applied only when required

> “Don’t update now if you can do it later.”

---

## Key Idea
When a segment is **fully inside the update range**:
- Update the current node directly
- **Do not go down to children**
- Store pending updates in a separate array called **lazy[]**

---


# Segment Tree – Lazy Propagation (Range Update + Range Query)

## Motivation
- **Point Update**: Update a single index → `O(log N)`
- **Range Update (naive)**:  
  Update every index in `[L, R]` using point update  
  ⛔ Time = `O(N log N)` (too slow)

👉 We need a faster way to update **entire ranges** efficiently.

---

## What is Lazy Propagation?
Lazy Propagation is an **optimization technique** for Segment Trees that allows:

- **Range updates** in `O(log N)`
- Without immediately updating all child nodes
- Updates are **postponed** and applied only when required

> “Don’t update now if you can do it later.”

---

## Key Idea
When a segment is **fully inside the update range**:
- Update the current node directly
- **Do not go down to children**
- Store pending updates in a separate array called **lazy[]**

---

## Data Structures Used

### Segment Tree
```cpp
vector<int> segTree(4 * N);
```

### Lazy Tree
```cpp
vector<int> lazy(4 * N, 0);
```
- lazy[i] stores pending updates for node i
- Same size as segment tree

## Types of Ranges

For a node representing range `[L, R]` and query range `[ql, qr]`:

### 1. No Overlap
**Condition:** `R < ql OR L > qr`

**Action:** Do nothing, return

### 2. Complete Overlap
**Condition:** `ql <= L AND R <= qr`

**Actions:**
- Update node directly
- Store update in lazy children
- Stop recursion

### 3. Partial Overlap

**Actions:**
- Push lazy updates (if any)
- Recurse left & right
- Update current node from children

---

## Lazy Update Strategy (Important)

### Before using a node:

Always check:
```cpp
if (lazy[i] != 0)
```

Then:
1. Apply lazy value to `segTree[i]`
2. Propagate lazy value to children
3. Reset `lazy[i] = 0`

---

## Why Lazy Works

Instead of updating each element, we:

1. Update range sum at once
2. Store pending updates
3. Apply them only when needed

**Result:** `O(N log N) → O(log N)`

Range Update Pseudocode
```cpp
updateRange(i, L, R, ql, qr, val):

    // Step 1: Resolve pending lazy updates
    if lazy[i] != 0:
        segTree[i] += (R - L + 1) * lazy[i]
        if L != R:
            lazy[2*i+1] += lazy[i]
            lazy[2*i+2] += lazy[i]
        lazy[i] = 0

    // Step 2: No overlap
    if R < ql OR L > qr:
        return

    // Step 3: Complete overlap
    if ql <= L AND R <= qr:
        segTree[i] += (R - L + 1) * val
        if L != R:
            lazy[2*i+1] += val
            lazy[2*i+2] += val
        return

    // Step 4: Partial overlap
    mid = (L + R) / 2
    updateRange(2*i+1, L, mid, ql, qr, val)
    updateRange(2*i+2, mid+1, R, ql, qr, val)

    segTree[i] = segTree[2*i+1] + segTree[2*i+2]
```
Range Query with Lazy Propagation
```cpp
query(i, L, R, ql, qr):

    if lazy[i] != 0:
        segTree[i] += (R - L + 1) * lazy[i]
        if L != R:
            lazy[2*i+1] += lazy[i]
            lazy[2*i+2] += lazy[i]
        lazy[i] = 0

    if R < ql OR L > qr:
        return 0

    if ql <= L AND R <= qr:
        return segTree[i]

    mid = (L + R) / 2
    return query(2*i+1, L, mid, ql, qr)
         + query(2*i+2, mid+1, R, ql, qr)
```



## Time & Space Complexity

### Time

| Operation | Complexity |
|-----------|-----------|
| Build | O(N) |
| Range Update | O(log N) |
| Range Query | O(log N) |

### Space

| Structure | Space |
|-----------|-------|
| Segment Tree | O(4N) |
| Lazy Tree | O(4N) |

### Comparison

| Feature | Normal Segment Tree | Lazy Segment Tree |
|---------|-------------------|------------------|
| Point Update | O(log N) | O(log N) |
| Range Update | O(N log N) | O(log N) |
| Extra Space | ❌ | ✅ Lazy Tree |

## Key Takeaways
- Lazy propagation avoids unnecessary recursion
- Updates are postponed, not ignored
- Always resolve lazy before accessing node
- Extremely important for range updates

## Common Mistakes

❌ Forgetting to clear lazy[i]
❌ Not propagating lazy to children
❌ Updating children immediately (kills optimization)
❌ Forgetting (R - L + 1) multiplier

## Interview Tip

If interviewer asks:

“How do you optimize range updates in segment trees?”

Answer:

“Using Lazy Propagation to defer updates and reduce time complexity to O(log N).”