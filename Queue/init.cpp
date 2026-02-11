#include<bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.front() << endl; 
    q.pop();
    cout << q.front() << endl; 
    cout << q.size() << endl;  
    cout << q.empty() << endl; 

    priority_queue<int> pq;
    pq.push(3);
    pq.push(1);
    pq.push(2);
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.empty() << endl;
    
    return 0;
}