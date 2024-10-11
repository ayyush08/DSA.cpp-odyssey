#include<iostream>
using namespace std;
int main()
{
    int age;
    cout << "Enter your age: ";
    cin >> age;
    if (age<18)
    {
        /* code */
        cout << "Not an adult";
    }
    else{
        cout << "Adult";
    }
    
return 0;
}