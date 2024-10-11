// #include <iostream>
// using namespace std;
// int main(){
//     cout << "Hey Curator!" << endl << "Hey Ayush";
//     cout << "Hey Curator!" << endl << "Hey Ayush";
// }
#include <iostream>
#include <map>
using namespace std;

int main()
{
    int arr[] = {10, 20, 30, 30, 30, 20};
    map<int, int> Freqtable;
    for (int i = 0; i < 6; i++)
    {
        Freqtable[arr[i]]++;
    }
    map<int, int>::iterator it;
    for (it = Freqtable.begin();it != Freqtable.end(); it++)
    {
        cout << it->first << " : " << it->second << endl;
    }

    return 0;
}