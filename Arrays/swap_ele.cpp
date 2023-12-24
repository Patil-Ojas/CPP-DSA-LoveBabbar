
#include <iostream>

void swap_eles(int arr[], int size)
{
    for (int i=0; i<size-1; i=i+2)
    {
        int temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
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

    swap_eles(arr, size);

    for (int i=0; i<size; i++)
    {
        std::cout<<arr[i]<<' ';
    }

    return 0;
}