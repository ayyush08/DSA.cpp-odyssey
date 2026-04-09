# Square Root Decomposition

Square Root Decomposition is a technique used to reduce the time complexity of range queries (like sum, product, min/max) from \(O(N)\) to \(O(\sqrt{N})\). It works by dividing a large array into smaller **blocks** (or **chunks**).

## 1. The Core Problem: Range Sum Queries

Given an array of size \(N\) and \(Q\) queries to find the sum from index \(L\) to \(R\):

- **Brute force:** Iterate from \(L\) to \(R\) for every query.
- **Complexity:** \(O(Q \times N)\). If both \(N\) and \(Q\) are \(10^5\), this will exceed time limits.
- **Optimization goal:** Answer queries faster, ideally in `(O(sqrt{N}))` time.

## 2. How It Works

- Divide the array into blocks of size approximately \(\sqrt{N}\).

- **Pre-processing (building):**
    - **Block size:** `blockSize = floor(sqrt(N))`
    - **Blocks array:** Create an auxiliary array `blocks[]` to store the sum of each block.
    - **Indexing:** Any index `i` belongs to block `i / blockSize`.

- **Example:** For \(N = 9\), \(sqrt{9} = 3\)
    - Block 0: indices `[0, 1, 2]`
    - Block 1: indices `[3, 4, 5]`
    - Block 2: indices `[6, 7, 8]`

## 3. Handling Queries (\(L\) to \(R\))

When querying a range, there are two cases.

### Case 1: \(L\) and \(R\) are in the same block

- If both indices are in the same block, iterate from \(L\) to \(R\) and sum directly.
- Complexity: \(O(\sqrt{N})\) in the worst case.

### Case 2: \(L\) and \(R\) are in different blocks

Split the range into three parts:

- **Left partial block:** from \(L\) to the end of \(L\)'s block.
- **Middle full blocks:** blocks completely between \(L\) and \(R\). Use precomputed values from `blocks[]` (\(O(1)\) per block).
- **Right partial block:** from the start of \(R\)'s block to \(R\).

**Total complexity:** \(O(\sqrt{N})\)

## 4. Update Operation

If an element at index \(i\) is updated:

- Compute `diff = newValue - oldValue`
- Update original array: `nums[i] = newValue`
- Update block sum: `blocks[i / blockSize] += diff`
- **Complexity:** \(O(1)\)

## 5. When to Use

- **Constraint fit:** When `(Q * sqrt{N})` fits within time limits.
- **Implementation speed:** Easier and faster to code than a Segment Tree.
- **Light updates:** Good for point updates; not meant for heavy range updates with lazy propagation.

## 6. Pseudocode Logic

### Building the blocks
```cpp
int blockSize = ceil(sqrt(n));
vector<int> blocks(blockSize, 0);
for (int i = 0; i < n; i++) {
    blocks[i / blockSize] += nums[i];
}
```

### Querying the sum
```cpp
int sum = 0;
int startBlock = L / blockSize;
int endBlock = R / blockSize;

if (startBlock == endBlock) {
    for (int i = L; i <= R; i++) sum += nums[i];
} else {
    // 1. Left Partial
    for (int i = L; i < (startBlock + 1) * blockSize; i++) sum += nums[i];
    // 2. Middle Full Blocks
    for (int b = startBlock + 1; b < endBlock; b++) sum += blocks[b];
    // 3. Right Partial
    for (int i = endBlock * blockSize; i <= R; i++) sum += nums[i];
}
return sum;
```

