// #include <iostream>
// using namespace std;
// int main(){
//     cout << "Hey Curator!" << endl << "Hey Ayush";
//     cout << "Hey Curator!" << endl << "Hey Ayush";
// }
#include <bits/stdc++.h>
using namespace std;

int wordCount(string sent){
    int count = 1;

    for(int i = 0; i < sent.size(); i++)
    {
        if(sent[i] == ' ')
        {
            count++;
        }
    }
    return (count);
}

vector<string> func(vector<string> sent)
{
    int s = sent.size();

    vector<string> result;
    for (int i = 0; i < s; i++)
    {   
        int count = wordCount(sent[i]);
        if(count ==1) result.push_back(sent[i]);
    }

    return result;
    
}

int main()
{
    vector<string> names = {"ayush kumar", "ayush", "ayush kumar"};
    vector<string> res = func(names);
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }
    
    return 0;
}