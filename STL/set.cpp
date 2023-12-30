
#include <iostream>
#include <set>
using namespace std;


int main()
{
    // only unqiue elements are present
    // implemented behind the scenes using bst
    // return elements in sorted element
    // lil slower than unordered set

    set <int> s;

    // O(logn)
    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(8);
    s.insert(8);
    s.insert(8);
    s.insert(3);
    s.insert(3);
    s.insert(0);

    for (auto i:s)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    set<int>::iterator it = s.begin();
    it++;

    s.erase(it);

    for (auto i:s)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    // here, returns if element is present or not.
    cout<<"coutn: "<<s.count(5)<<endl;
    
    // find index of a number
    set<int> ::iterator itr = s.find(5);
    cout<<"value "<<*itr<<endl;
    itr++;
    cout<<"value "<<*itr<<endl;
    
    return 0;

}