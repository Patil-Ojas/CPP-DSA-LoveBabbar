#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // max heap
    priority_queue<int> pq;

    pq.push(4);
    pq.push(2);
    pq.push(3);
    pq.push(1);

    cout<<"pq top is "<<pq.top()<<endl;
    pq.pop();
    cout<<"now pq top is "<<pq.top()<<endl;
    if (!pq.empty())
        cout<<"now pq size is "<<pq.size()<<endl<<endl;

    priority_queue<int, vector<int>, greater<int>> minheap;
     
    minheap.push(4);
    minheap.push(2);
    minheap.push(3);
    minheap.push(1);

    cout<<"minheap top is "<<minheap.top()<<endl;
    minheap.pop();
    cout<<"now minheap top is "<<minheap.top()<<endl;
    if (!minheap.empty())
        cout<<"now minheap size is "<<minheap.size()<<endl;

    return 0;
}