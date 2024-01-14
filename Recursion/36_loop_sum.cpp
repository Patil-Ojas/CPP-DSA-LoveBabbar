
#include <iostream>
using namespace std;

int getSum(int arr[], int size)
{
    if (size-1 == 0)
    {
        // cout<<"nrij"<<endl;
        return arr[0]+arr[1];
    }
    else
    {
        // cout<<arr[size]<<endl;
        return arr[size] + getSum(arr, size-1);
    }
}

int main()
{
    int arr[] = {3, 4, 6, 8, 3, 7, 8};
    int size = sizeof(arr)/sizeof(arr[0])-1;

    int sum = getSum(arr, size);
    cout<<"Sum: "<<sum<<endl;
    return 0;
}