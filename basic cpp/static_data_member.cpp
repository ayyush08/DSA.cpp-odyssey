#include<bits/stdc++.h>
using namespace std;


class item{
    int number;
    static int count;
    public:
    void getdata(){
        number = ++count;
    }
    static void showCount(){
        cout << "Count: " << count << endl;
    }
    void showNumber(){
        cout << "Number: " << number << endl;
    }
};

int item::count;//scope-resolution operator
int main()
{
    // item t1,t2,t3;
    // t1.showCount();
    // t2.showCount();
    // t3.showCount();
    // t1.getdata(100);
    // t2.getdata(200);
    // t3.getdata(300);
    // t1.showCount();
    // t2.showCount();
    // t3.showCount();
    item t1,t2;
    t1.getdata();
    t2.getdata();
    t1.showNumber();
    t2.showNumber();
    item::showCount();
    item t3;
    t3.getdata();
    t3.showNumber();
    item::showCount();
    
return 0;
}