
// dynamic, random access possible

#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> d;

    d.push_back(3);
    d.push_front(7);
    d.push_front(10);

    for (int i=0; i<d.size(); i++)
    {
        cout<<d[i]<<" ";
    }
    cout<<endl;

    d.pop_back();
    d.pop_front();

    for (int i=0; i<d.size(); i++)
    {
        cout<<d[i]<<" ";
    }
    cout<<endl;

    d.push_back(3);
    d.push_front(10);
    for (int i=0; i<d.size(); i++)
    {
        cout<<d[i]<<" ";
    }
    cout<<endl;

    cout<<"element at 2rd index: "<<d.at(1)<<endl;
    cout<<"empty or nah: "<<d.empty()<<endl;
    cout<<"first element: "<<d.front()<<endl;
    cout<<"last element: "<<d.back()<<endl;
    
    //size changes capacity doesnt change
    cout<<"size before erase: "<<d.size()<<endl;
    d.erase(d.begin(), d.begin()+2);
    cout<<"size after erase: "<<d.size()<<endl; 

    for (int i=0; i<d.size(); i++)
    {
        cout<<d[i]<<" ";
    }


    return 0;
}