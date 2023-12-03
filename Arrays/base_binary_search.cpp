
#include <iostream>

void binary_search(int arr[], int size, int ele)
{
    int low=0;
    int high=size-1;
    
    // same as (low+high)/2, just computationally better for big ahh numbers
    int mid = low + (high-low)/2;

    while (low<=high)
    {
        if (arr[mid]==ele)
        {
            std::cout<<"ele found at: "<<mid;
            return;
        }
        else if (arr[mid] < ele)
        {
            low = mid + 1;
        }
        else if (arr[mid] >  ele)
        {
            high = mid - 1;
        }
        else
        {
            std::cout<<"no ele rbug";
        }
        mid = low + (high-low)/2;
    }
}

int main()
{
    int size;
    std::cout<<"enter size:";
    std::cin>>size;
 
    int arr[size];
    for (int i=0; i<size; i++)
    {
        std::cin>>arr[i];
    }

    std::cout<<"enter ele:";
    int k;
    std::cin>>k;

    binary_search(arr, size, k);
    return 0;
}