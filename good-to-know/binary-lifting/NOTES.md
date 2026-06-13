# Binary Lifting

Binary Lifting is a technique used on trees to answer ancestor-related queries efficiently.

The most common application is: **Find the K-th ancestor of a node.**

Instead of moving upward one node at a time, Binary Lifting allows us to jump upward in powers of two.

## Motivation

Consider a large tree with up to 2×10⁵ or 5×10⁵ nodes.

Suppose we need to answer queries like:

- 1st ancestor of X
- 18th ancestor of X
- 50th ancestor of X
- K-th ancestor of X

## Naive Approach

Move upward one step at a time: X → parent → grandparent → ...

For a K-th ancestor query: **Time Complexity = O(K)**

If there are many queries: **Q queries ⟹ O(Q × K)**

This becomes too slow.

## Core Idea

Instead of taking:
- 1 jump
- 1 jump
- 1 jump
- ...

Take larger jumps:
- 1 jump
- 2 jumps
- 4 jumps
- 8 jumps
- 16 jumps
- ...

These are powers of two: 2^0, 2^1, 2^2, 2^3, ...

This is the fundamental idea behind Binary Lifting.

## Why Powers of Two?

Every integer can be represented uniquely as a sum of powers of two.

Example: 14 = 8 + 4 + 2 = 2^3 + 2^2 + 2^1

Binary representation: 14 = 1110₂

Each set bit tells us which jump sizes are needed:
- 2^3 → take
- 2^2 → take
- 2^1 → take
- 2^0 → skip

So the 14th ancestor = 8-jump + 4-jump + 2-jump

This property is unique and unambiguous for powers of two.

## What Information Do We Store?

For every node, store: `parent[node][j]`

Meaning: If we start from node and make a jump of 2^j, which ancestor do we reach?

Formally: `parent[node][j]` = the 2^j-th ancestor of node

Examples:
- `parent[node][0]` = 1st ancestor
- `parent[node][1]` = 2nd ancestor
- `parent[node][2]` = 4th ancestor
- `parent[node][3]` = 8th ancestor
- and so on...

## Binary Lifting Table

We create a 2D table:

```cpp
vector<vector<int>> parent;
```

- **Rows**: Nodes
- **Columns**: Jump powers (0, 1, 2, 3, ...)
- **Meaning**: `parent[node][j]` stores the 2^j-th ancestor

## Recurrence Relation

This is the most important formula.

Suppose we want `parent[node][j]`, which is the 2^j-th ancestor.

Observe: 2^j = 2^(j-1) + 2^(j-1)

Therefore:
- Jump 2^(j-1) steps
- From that ancestor, jump another 2^(j-1) steps

Hence:
```
parent[node][j] = parent[parent[node][j-1]][j-1]
```

This is the Binary Lifting recurrence.

## Table Dimensions

Suppose: N = number of nodes

Maximum ancestor jump required: 2^j ≤ N

Therefore: j ≤ log₂(N)

So:
- rows = N
- columns = log₂(N) + 1

Table size: N × (log₂N + 1)

## Building the First Column

Column `parent[node][0]` stores the immediate parent. This can be filled using DFS.

Example:

```cpp
void dfs(int node, int par)
{
    parent[node][0] = par;

    for(auto child : adj[node])
    {
        if(child == par) continue;
        dfs(child, node);
    }
}
```

For root: `parent[root][0] = -1;`

## Building the Entire Table

```cpp
for(int j = 1; j <= LOG; j++)
{
    for(int node = 0; node < n; node++)
    {
        if(parent[node][j-1] != -1)
        {
            parent[node][j] = parent[parent[node][j-1]][j-1];
        }
        else
        {
            parent[node][j] = -1;
        }
    }
}
```

**Time Complexity**: O(N log N)

## Finding the K-th Ancestor

Convert K into binary.

Example: K = 13, Binary = 1101

Meaning: 13 = 8 + 4 + 1 = 2^3 + 2^2 + 2^0

So:
- Take 8-jump
- Take 4-jump
- Take 1-jump
- Skip 2-jump (because that bit is not set)

Algorithm:

```cpp
int kthAncestor(int node, int k)
{
    for(int j = 0; j <= LOG; j++)
    {
        if(k & (1 << j))
        {
            node = parent[node][j];
            if(node == -1)
                return -1;
        }
    }
    return node;
}
```

The binary representation of k automatically tells us which jumps to take.

## Complexity Analysis

| Operation | Complexity |
|-----------|------------|
| Build Table | O(N log N) |
| K-th Ancestor Query | O(log N) |
| Space | O(N log N) |

## Key Points for Interviews

**Definition**: Binary Lifting stores the 2^j-th ancestor of every node.

**Why powers of two?** Because every integer has a unique binary representation.

**Meaning of `parent[node][j]`**: The 2^j-th ancestor of node.

**Recurrence**: `parent[node][j] = parent[parent[node][j-1]][j-1]`

**Table Size**: N × (log₂N + 1)

**Complexity**:
| Operation | Complexity |
|-----------|------------|
| Build Table | O(N log N) |
| K-th Ancestor Query | O(log N) |
| Space | O(N log N) |

## Intuition in One Line

Binary Lifting replaces moving up the tree one step at a time with jumps of size 1, 2, 4, 8, 16..., allowing ancestor queries to be answered in O(log N) time instead of O(K).