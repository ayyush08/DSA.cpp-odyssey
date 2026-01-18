// 2940. Find Building Where Alice and Bob Can Meet
// You are given a 0-indexed array heights of positive integers, where heights[i] represents the height of the ith building.

// If a person is in building i, they can move to any other building j if and only if i < j and heights[i] < heights[j].

// You are also given another array queries where queries[i] = [ai, bi]. On the ith query, Alice is in building ai while Bob is in building bi.

// Return an array ans where ans[i] is the index of the leftmost building where Alice and Bob can meet on the ith query. If Alice and Bob cannot move to a common building on query i, set ans[i] to -1.

// Example 1:

// Input: heights = [6,4,8,5,2,7], queries = [[0,1],[0,3],[2,4],[3,4],[2,2]]
// Output: [2,5,-1,5,2]
// Explanation: In the first query, Alice and Bob can move to building 2 since heights[0] < heights[2] and heights[1] < heights[2].
// In the second query, Alice and Bob can move to building 5 since heights[0] < heights[5] and heights[3] < heights[5].
// In the third query, Alice cannot meet Bob since Alice cannot move to any other building.
// In the fourth query, Alice and Bob can move to building 5 since heights[3] < heights[5] and heights[4] < heights[5].
// In the fifth query, Alice and Bob are already in the same building.
// For ans[i] != -1, It can be shown that ans[i] is the leftmost building where Alice and Bob can meet.
// For ans[i] == -1, It can be shown that there is no building where Alice and Bob can meet.
// Example 2:

// Input: heights = [5,3,8,2,6,1,4,6], queries = [[0,7],[3,5],[5,2],[3,0],[1,6]]
// Output: [7,6,-1,4,6]
// Explanation: In the first query, Alice can directly move to Bob's building since heights[0] < heights[7].
// In the second query, Alice and Bob can move to building 6 since heights[3] < heights[6] and heights[5] < heights[6].
// In the third query, Alice cannot meet Bob since Bob cannot move to any other building.
// In the fourth query, Alice and Bob can move to building 4 since heights[3] < heights[4] and heights[0] < heights[4].
// In the fifth query, Alice can directly move to Bob's building since heights[1] < heights[6].
// For ans[i] != -1, It can be shown that ans[i] is the leftmost building where Alice and Bob can meet.
// For ans[i] == -1, It can be shown that there is no building where Alice and Bob can meet.

// Constraints:

// 1 <= heights.length <= 5 * 104
// 1 <= heights[i] <= 109
// 1 <= queries.length <= 5 * 104
// queries[i] = [ai, bi]
// 0 <= ai, bi <= heights.length - 1

#include <bits/stdc++.h>
using namespace std;

// Intuition: Use Range Maximum Index Query to find the maximum height index in the range of Alice and Bob's buildings. Utilise binary search to find the leftmost building they can meet.

//Time Complexity: O(N+Q*logN*logN): logN squared because for each query we are performing a binary search (logN) and in each step of binary search we are querying the segment tree (logN).
//Space Complexity: O(4N) for segment tree.

struct SegmentTree
{
    vector<int> segmentTree;
    void init(int n) { segmentTree.assign(4 * n, 0); }
    void build(vector<int> &arr, int i, int l, int r)
    {
        if (l == r)
        {
            segmentTree[i] = l;
            return;
        }
        int mid = l + (r - l) / 2;
        build(arr, 2 * i + 1, l, mid);
        build(arr, 2 * i + 2, mid + 1, r);

        segmentTree[i] =
            (arr[segmentTree[2 * i + 1]] >= arr[segmentTree[2 * i + 2]])
                ? segmentTree[2 * i + 1]
                : segmentTree[2 * i + 2];
    }
    int query(int start, int end, int i, int l, int r, vector<int> &arr)
    {
        if (l > end || r < start)
            return -1;
        if (l >= start && r <= end)
            return segmentTree[i];

        int mid = l + (r - l) / 2;
        int left = query(start, end, 2 * i + 1, l, mid, arr);
        int right = query(start, end, 2 * i + 2, mid + 1, r, arr);
        if (left == -1)
            return right;
        if (right == -1)
            return left;

        return arr[left] >= arr[right] ? left : right;
    }
};
class Solution
{
public:
    vector<int> leftmostBuildingQueries(vector<int> &heights, vector<vector<int>> &queries)
    {
        int n = heights.size();
        SegmentTree segTree;
        segTree.init(n);
        segTree.build(heights, 0, 0, n - 1);
        vector<int> ans;

        for (auto q : queries)
        {
            int alice = min(q[0], q[1]);
            int bob = max(q[0], q[1]);

            if (alice == bob || heights[alice] < heights[bob])
            {
                ans.push_back(bob);
                continue;
            }

            int low = bob + 1;
            int high = n - 1;
            int leftMost = -1;

            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                int buildingIndex = segTree.query(low, mid, 0, 0, n - 1, heights);

                if (heights[buildingIndex] > max(heights[alice], heights[bob]))
                {
                    leftMost = buildingIndex;
                    high = mid - 1;
                }
                else
                    low = mid + 1;
            }
            ans.push_back(leftMost);
        }
        return ans;
    }
};