#include<iostream>
#include<fstream>
using namespace std;

// int main()
// {
//     const string path = "D:\\Striver's A2Z\\basic cpp\\FIlehandler\\";
//     ofstream fout;
//     fout.open(path+"country.txt");
//     fout << "India" << endl;
//     fout << "USA" << endl;
//     fout << "UK" << endl;
//     fout.close();
//     fout.open(path+"capital.txt");
//     fout << "New Delhi" << endl;
//     fout << "Washington, D.C." << endl;
//     fout << "London" << endl;
//     fout.close();
//     const int n = 80;
//     char s[n];
//     ifstream fin;
//     fin.open(path+"country.txt");
//     cout << "Contents of country.txt" << endl;
//     while(fin)
//     {
//         fin.getline(s, n);
//         cout << s << endl;
//     }
//     fin.close();
//     fin.open(path+"capital.txt");
//     cout << "Contents of capital.txt" << endl;
//     while(fin)
//     {
//         fin.getline(s, n);
//         cout << s << endl;
//     }
//     fin.close();
//     cout << "End of program" << endl;
// return 0;
// }

int main(){
    char s[30];
    ofstream fout;
    ifstream fin;
    fout.open("data",ios::app);
    fout << "Hello world again";
    fout.close();
    fin.open("data",ios::in);
    fin.getline(s,30);
    cout << s << endl;
}