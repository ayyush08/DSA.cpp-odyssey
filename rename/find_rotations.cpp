


#include <bits/stdc++.h>
using namespace std;

int findKRotation(vector<int> &arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    int index = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        //search space is already sorted
        //then arr[low] will always be
        //the minimum in that search space:
        if (arr[low] <= arr[high]) {
            if (arr[low] < ans) {
                index = low;
                ans = arr[low];
            }
            break;
        }

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            // keep the minimum:
            if (arr[low] < ans) {
                index = low;
                ans = arr[low];
            }

            // Eliminate left half:
            low = mid + 1;
        }
        else { //if right part is sorted:

            // keep the minimum:
            if (arr[mid] < ans) {
                index = mid;
                ans = arr[mid];
            }

            // Eliminate right half:
            high = mid - 1;
        }
    }
    return index;
}

int main()
{
    vector<int> arr = {13881, 13969, 14173, 15115, 15253, 15484,15700, 15781, 15967, 16290, 17294, 17448, 17950, 17987, 18814, 19253, 19290,20317, 20350 ,20406 ,21360 ,21422, 21717, 22168, 22222, 22374, 22992 ,23232, 23780, 23971, 24062, 24407, 24421, 24790, 24998, 25457, 25682, 25760, 26288, 26330, 26429, 26676, 26773, 27012, 27514 ,27544 ,28460 ,28539 ,29061 ,29528 ,30113 ,30215,30352, 31082 ,31433 ,31448 ,31604, 31825 ,32233 ,41 ,53 ,1129 ,1159 ,1162 ,1171, 1536 ,1933 ,2219 ,2678 ,3024, 4452 ,4571, 4664, 5368 ,5675, 5805, 6050 ,6425, 6549, 6803, 7459, 7683, 8706, 8906, 9040, 9269,10431 ,10609 ,10713 ,10975 ,11376 ,11458 ,11711, 11830, 11968 ,12439 ,12453, 12805 ,12918 ,13670 ,13881};
    int ans = findKRotation(arr);
    cout << "The array is rotated " << ans << " times.\n";
    return 0;
}

