
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v;

    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(9);

    cout<<"find 5 "<<binary_search(v.begin(), v.end(), 5)<<endl;

    cout<<"Lower bound: "<<lower_bound(v.begin(), v.end(), 5)-v.begin()<<endl;
    cout<<"Upper bound: "<<upper_bound(v.begin(), v.end(), 4)-v.end()<<endl;

    int a = 3;
    int b = 5;

    cout<<"max: "<<max(a, b);
    cout<<"min: "<<min(a, b);

    cout<<a<<" "<<b;
    swap(a, b);
    cout<<a<<" "<<b;

    string str;
    reverse(str.begin(), str.end());
    cout<<"string "<<str<<endl;

    for(int i:v)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    rotate(v.begin(), v.begin()+1, v.end());
    
    for(int i:v)
    {
        cout<<i<<" ";
    }
    cout<<endl;


    // sorting uses an introsort algo which is a mixture of 3 algos: quicksort, heapsort and insertion sort
    sort(v.begin(), v.end());
    for(int i:v)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    return  0;
}