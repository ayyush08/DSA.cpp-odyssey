#include<iostream>
using namespace std;
int main()
{
    string s = "Curator";
    int len = s.size();
    int len2 = s.length();
    
    cout << s[len-1] << "\n";
    cout << s[len2-1];
return 0;
}