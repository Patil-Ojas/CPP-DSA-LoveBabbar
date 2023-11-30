

#include <iostream>

int main()
{
    // init with 0's
    int arr0[5] = {0};
    int len = sizeof(arr0)  / sizeof(arr0[0]);
    
    // init with whatever the fk u want
    std::fill(arr0, arr0+3, 42);

    for (int i=0; i<len; i++)
    {
        std::cout<<arr0[i]<<'\n';
    }

    return 0;
}