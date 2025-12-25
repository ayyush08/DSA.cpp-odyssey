# Kosaraju Algorithm

Used to find strongly connected components (SCCs) in a directed graph. A component is called a Strongly Connected Component (SCC) only if for every possible pair of vertices (u, v) inside that component, u is reachable from v and v is reachable from u.

**Note:** SCCs are only valid for directed graphs.

## Algorithm Steps

1. Perform a DFS traversal of the original graph and store vertices in a stack according to their finishing times
2. Reverse the direction of all edges to obtain the transposed graph
3. Pop vertices from the stack and perform DFS on the transposed graph
4. Collect the strongly connected components found during DFS traversals

## Complexity

| Metric | Value |
|--------|-------|
| Time Complexity | O(V + E) |
| Space Complexity | O(V) |

---

# Tarjan's Algorithm

Tarjan's algorithm finds all bridges in a connected undirected graph. A bridge is an edge that, when removed, increases the number of connected components.

## Core Concepts

### Discovery and Low Times

| Array | Purpose |
|-------|---------|
| **Discovery Time** | Time when a node is first visited during DFS (unique, incremental) |
| **Lowest Time** | Minimum discovery time reachable from a node, considering descendants and back edges |

### Bridge Identification

An edge (u, v) is a bridge if `low[v] > tin[u]`, meaning v and its descendants cannot reach u or u's ancestors without this edge.

## Algorithm Approach

1. Create adjacency lists from graph edges
2. Initialize discovery, lowest time, and visited arrays; set timer to 0
3. Begin DFS from an arbitrary node with parent = -1
4. For each node:
    - Mark as visited, set discovery and lowest time to current timer value
    - Increment timer
5. Process neighbors:
    - Skip the parent node
    - If unvisited: recursively call DFS and update lowest time
    - If visited (not parent): update lowest time based on neighbor's discovery time
6. Check condition `low[neighbor] > tin[current_node]` to identify bridges
7. Return the list of identified bridges

