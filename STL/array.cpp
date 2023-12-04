
// cpp stl - algorithms
//         - containers


#include <iostream>
#include <array>
using namespace std;

int main()
{
    int basic[4] = {3, 4, 7, 8};

    //static array
    array<int, 4> arr= {1, 2, 3, 5};

    for (int i=0; i<arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    cout<<"element at 3rd index: "<<arr.at(3)<<endl;
    cout<<"empty or nah: "<<arr.empty()<<endl;
    cout<<"first element: "<<arr.front()<<endl;
    cout<<"last element: "<<arr.back()<<endl;

    return 0;
}