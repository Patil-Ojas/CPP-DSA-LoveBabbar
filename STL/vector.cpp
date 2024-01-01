
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //dynamic array - when v gets full, it creates a new duplicate array of DOUBLE size and discards the prev array.
    vector<int> v;

    cout<<"vector arr size: "<<v.size()<<endl;
    cout<<"vector arr capacity: "<<v.size()<<endl;

    v.push_back(10);
    cout<<"vector arr size: "<<v.size()<<endl;
    cout<<"vector arr capacity: "<<v.capacity()<<endl;
 
    v.push_back(20);
    cout<<"vector arr size: "<<v.size()<<endl;
    cout<<"vector arr capacity: "<<v.capacity()<<endl;
    
    v.push_back(30);
    cout<<"vector arr size: "<<v.size()<<endl;
    cout<<"vector arr capacity: "<<v.capacity()<<endl;


    cout<<"element at 2rd index: "<<v.at(2)<<endl;
    cout<<"empty or nah: "<<v.empty()<<endl;
    cout<<"first element: "<<v.front()<<endl;
    cout<<"last element: "<<v.back()<<endl;

    //reduces size note mem
    for (int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    v.pop_back();
    for (int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;

    // clearing an array just cleans its size, it doesnt yeet its memory
    cout<<"vector arr size: "<<v.size()<<endl;
    cout<<"vector arr capacity: "<<v.capacity()<<endl;

    v.clear();

    cout<<"vector arr size: "<<v.size()<<endl;
    cout<<"vector arr capacity: "<<v.capacity()<<endl;
    cout<<endl;


    vector <int> a(5, 1);
    for (int i=0; i<a.size(); i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    vector <int> kapy(a);
    for (int i=0; i<kapy.size(); i++)
    {
        cout<<kapy[i]<<" ";
    }
    cout<<endl;

    return 0;    
}