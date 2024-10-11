#include<bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i=0,j=0;
        vector<int>spiral;
        int top=0,bottom = m-1,right=n-1,left=0;
        while(top<=bottom && left<=right){
            for(int i=left;i<=right;i++)
                spiral.push_back(matrix[top][i]);
            top++;
            for(int i=top;i<=bottom;i++)
                spiral.push_back(matrix[i][right]);
            right--;
            if(top<=bottom){
            for(int i=right;i>=left;i--)
                spiral.push_back(matrix[bottom][i]);
            bottom--;
            }
            if(left<=right){
            for(int i=bottom;i>=top;i--)
                spiral.push_back(matrix[i][left]);
            left++;
            }
        }
        return spiral;
    }

int main()
{
    vector < vector < int >> arr;
    arr =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> spiral = spiralOrder(arr);
    cout << "Spiral Order" << endl;
    for (int i = 0; i < spiral.size(); i++) {
        cout << spiral[i] << " --> ";
    }
    cout << "\n";
return 0;
}