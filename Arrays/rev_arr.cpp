
#include <iostream>

void rev_arrr(int arr[], int size)
{
    for (int i=0; i<size/2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[size-i-1];
        arr[size-i-1] = temp;
    }
}

int main()
{
    int size;
    std::cin>>size;

    int arr[size];
    for (int i=0; i<size; i++)
    {
        std::cin>>arr[i];
    }

    rev_arrr(arr, size);

    for (int i=0; i<size; i++)
    {
        std::cout<<arr[i]<<' ';
    }
    return 0;
}