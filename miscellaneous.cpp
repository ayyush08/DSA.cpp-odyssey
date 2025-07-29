#include<bits/stdc++.h>
using namespace std;


int search(int element,vector<int> &a){
    int low = 0,high= (a.size()-1)/2;
    int ans = -1, ind = -1;
    while(low<=high){
        int mid = (low + high) / 2;
        mid *= 2; // Adjust mid to account for the even index 

        if(a[mid]<=element){
            ans=a[mid];
            ind = mid;
            low = mid/2+1;
        }
        else high = mid/2-1;
    }
    return ind; // Return the index of the found element or the just smaller element
}

int main(){
    vector<int> a = {5,32,9,18,17,15,20,22,24,7};

    int target = 18;
    int n = a.size();

    int justSmallerIndex1 = search(target, a);
    int justSmallerIndex2 = search(a[justSmallerIndex1+1],a);
    if(a[justSmallerIndex2+1] == target){
        cout << "Element found at index: " << justSmallerIndex2 + 1 << endl;
    } else {
        cout << "Element not found, just smaller element is at index: " << justSmallerIndex2 + 1 << endl;
    }

    return 0;

}