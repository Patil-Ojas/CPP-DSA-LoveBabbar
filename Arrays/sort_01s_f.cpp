
// sort 01's
// given an array sort it by 0;s and 1's
// approaches - cconventional, count no of zeros, then count ones then make array
//            - sort method - nlogn
//            - two pointer - single trav

#include <iostream>

int main()
{
    int size;
    std::cin>>size;

    int ans[size];
    int arr[size];
    for (int i=0; i<size; i++)
    {
        std::cin>>arr[i];
    }

    // std::cout<<"bruh";
    int counter = 0;
    int i = 0;
    int j = size;

    while (i!=j)
    {
        if (arr[counter] == 0)
        {
            // std::cout<<"bruh";
            ans[i] = 0;
            i = i + 1;
            counter = counter + 1;
        }
        else if (arr[counter] == 1)
        {
            // std::cout<<"bruh";
            j = j - 1;
            ans[j] = 1;
            counter = counter + 1;
        }
    }
    
    for (int i=0; i<size; i++)
    {
        std::cout<<ans[i]<<" ";
    }
    return 0;
}