// You are given a 1-indexed array of integers nums of length n.

// We define a function greaterCount such that greaterCount(arr, val) returns the number of elements in arr that are strictly greater than val.

// You need to distribute all the elements of nums between two arrays arr1 and arr2 using n operations. In the first operation, append nums[1] to arr1. In the second operation, append nums[2] to arr2. Afterwards, in the ith operation:

// If greaterCount(arr1, nums[i]) > greaterCount(arr2, nums[i]), append nums[i] to arr1.
// If greaterCount(arr1, nums[i]) < greaterCount(arr2, nums[i]), append nums[i] to arr2.
// If greaterCount(arr1, nums[i]) == greaterCount(arr2, nums[i]), append nums[i] to the array with a lesser number of elements.
// If there is still a tie, append nums[i] to arr1.
// The array result is formed by concatenating the arrays arr1 and arr2. For example, if arr1 == [1,2,3] and arr2 == [4,5,6], then result = [1,2,3,4,5,6].

// Return the integer array result.

// Example 1:

// Input: nums = [2,1,3,3]
// Output: [2,3,1,3]
// Explanation: After the first 2 operations, arr1 = [2] and arr2 = [1].
// In the 3rd operation, the number of elements greater than 3 is zero in both arrays. Also, the lengths are equal, hence, append nums[3] to arr1.
// In the 4th operation, the number of elements greater than 3 is zero in both arrays. As the length of arr2 is lesser, hence, append nums[4] to arr2.
// After 4 operations, arr1 = [2,3] and arr2 = [1,3].
// Hence, the array result formed by concatenation is [2,3,1,3].
// Example 2:

// Input: nums = [5,14,3,1,2]
// Output: [5,3,1,2,14]
// Explanation: After the first 2 operations, arr1 = [5] and arr2 = [14].
// In the 3rd operation, the number of elements greater than 3 is one in both arrays. Also, the lengths are equal, hence, append nums[3] to arr1.
// In the 4th operation, the number of elements greater than 1 is greater in arr1 than arr2 (2 > 1). Hence, append nums[4] to arr1.
// In the 5th operation, the number of elements greater than 2 is greater in arr1 than arr2 (2 > 1). Hence, append nums[5] to arr1.
// After 5 operations, arr1 = [5,3,1,2] and arr2 = [14].
// Hence, the array result formed by concatenation is [5,3,1,2,14].
// Example 3:

// Input: nums = [3,3,3,3]
// Output: [3,3,3,3]
// Explanation: At the end of 4 operations, arr1 = [3,3] and arr2 = [3,3].
// Hence, the array result formed by concatenation is [3,3,3,3].

// Constraints:

// 3 <= n <= 10^5
// 1 <= nums[i] <= 10^9


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct SegmentTree
{
    vector<ll> tree;
    int size;
    void init(int n)
    {
        tree.assign(4 * n, 0);
        size = n;
    }

    void updateTree(int i, int l, int r,int compressedIndex)
    {
        if (l == r)
        {
            tree[i]++;
            return;
        }

        int mid = l + (r - l) / 2;
        if(compressedIndex<=mid) updateTree(2 * i + 1, l, mid,compressedIndex);
        else updateTree(2 * i + 2, mid + 1, r,compressedIndex);

        tree[i] = tree[2 * i + 1]+tree[2 * i + 2];
    }
    void update(int compressedIndex){
        updateTree(0,0,size-1,compressedIndex);
    }

    ll queryTree(int start, int end, int i, int l, int r)
    {
        if (l > end || r < start)
            return 0;

        if (l >= start && r <= end)
            return tree[i];

        int mid = l + (r - l) / 2;

        return queryTree(start, end, 2 * i + 1, l, mid) + queryTree(start, end, 2 * i + 2, mid + 1, r);
    }
    ll query(int from,int to){
        return queryTree(from,to,0,0,size-1);
    }
};
class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();

        vector<int>sorted(nums.begin(),nums.end());
        sort(sorted.begin(),sorted.end());

        //because nums[i] can be up to 10^9, we need to compress the values to use them in segment tree otherwise on submission we will get TLE/MLE

        unordered_map<int,int>compressedIndex;
        int ci = 0;
        for(int& x:sorted){
            if(!compressedIndex.count(x)){
                compressedIndex[x] = ci;
                ci++;
            }
        }

        int m = compressedIndex.size();

        SegmentTree segTree1;
        SegmentTree segTree2;

        segTree1.init(m);
        segTree2.init(m);

        vector<int> arr1;
        vector<int> arr2;

        arr1.push_back(nums[0]);
        segTree1.update(compressedIndex[nums[0]]);

        arr2.push_back(nums[1]);
        segTree2.update(compressedIndex[nums[1]]);

        for(int i=2;i<n;i++){
            int ci = compressedIndex[nums[i]];
            int c1 = segTree1.query(ci+1,m-1);
            int c2 = segTree2.query(ci+1,m-1);

            bool pushTo1 = false;

            if(c1>c2) pushTo1 = true;
            else if(c1<c2) pushTo1 = false;
            else pushTo1 = (arr1.size() <= arr2.size());

            if(pushTo1){
                arr1.push_back(nums[i]);
                segTree1.update(ci);
            }
            else{
                arr2.push_back(nums[i]);
                segTree2.update(ci);
            }
        }

        arr1.insert(arr1.end(),arr2.begin(),arr2.end());

        return arr1;

        
    }
};

//Time Complexity: O(nlogn) for sorting + O(nlogn) for segment tree operations = O(nlogn)
//Space Complexity: O(n) for segment tree + O(n) for compressedIndex + O(n) for result array = O(n)
