// linked list, we cant directly access

#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> d;

    d.push_back(3);
    d.push_front(7);
    d.push_front(10);

    //wont work
    // for (int i=0; i<d.size(); i++)
    // {
    //     cout<<d[i]<<" ";
    // }
    for (int i:d)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    d.pop_back();
    d.pop_front();
    for (int i:d)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    d.push_back(3);
    d.push_front(10);

    cout<<"empty or nah: "<<d.empty()<<endl;
    cout<<"first element: "<<d.front()<<endl;
    cout<<"last element: "<<d.back()<<endl;
    
    // size changes capacity doesnt change
    cout<<"size before erase: "<<d.size()<<endl;
    //wont work
    // d.erase(d.begin(), d.begin()+2);
    //also wont work
    // d.erase(d.begin()+2);
    d.erase(d.begin());
    cout<<"size after erase: "<<d.size()<<endl; 

    for (int i:d)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}

