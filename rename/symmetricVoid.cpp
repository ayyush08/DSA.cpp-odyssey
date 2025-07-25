#include<iostream>
using namespace std;
void symmetry(int n) {
    // Write your code here.
    int fSpace = 0,sSpace=2*n-2;
    for(int i=0;i<n;i++){
        for(int j=1;j<=n-(i);j++)
            cout << "*";
        for(int j=0;j<fSpace;j++)
            cout << ' ';
        for(int j=1;j<=n-(i);j++)
            cout << "*";
    fSpace+=2;
    cout << endl;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++)
            cout << "*";
        for(int j=0;j<sSpace;j++)
            cout << ' ';
        for(int j=1;j<=i;j++)
            cout << "*";
    sSpace-=2;
    cout << endl;
    }
}
void symmetry2(int n) {
    // Write your code here.
    int sp=2*n-2;
    for(int i=1;i<=2*n-1;i++){
        int stars =i;
        if(i>n) stars = 2*n-i;
        for(int j=1;j<=stars;j++){
            cout<< "* ";
        }
        for(int j=1;j<=sp;j++)
            cout << ' ';
        for(int j=1;j<=stars;j++){
            cout<< "* ";
        }
        if(i<=n) sp+=2;
        else sp-=2;
        cout<<endl;
    }
}
int main()
{
    int n;
    cin >> n;
    symmetry(n);
return 0;
}