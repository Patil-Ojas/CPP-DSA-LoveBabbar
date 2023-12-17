// first try baby tooo easy

#include <iostream>

int main()
{
    int size;
    std::cin>>size;

    int arr[size];
    for (int i=0; i<size; i++)
    {
        std::cin>>arr[i];
    }

    int i=0;
    int j=size-1;

    while (i!=j)
    {
        if ((arr[i]==0) and (arr[j]==1))
        {
            i++;
            j--;
        }
        else if ((arr[i]==1) and (arr[j]==0))
        {
            arr[i]=0;
            arr[j]=1;
            i++;
            j--;
        }
        else if (arr[j]==0)
        {
            i++;
        }
        else if (arr[i]==1)
        {
            j--;
        }
    }

    for (int i=0; i<size; i++)
    {
        std::cout<<arr[i]<<" ";
    }

    return 0;
}