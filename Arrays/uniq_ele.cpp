
// https://www.codingninjas.com/studio/problems/duplicate-in-array_893397?source=youtube&campaign=love_babbar_codestudio1

#include <iostream>

int find_uniq(int arr[], int size)
{
    int ans = 0;

    // like adds the first part of array and yeets the latter, resulting in a part which cannot be yeeted

    for (int i=0; i<size; i++)
    {
        ans = ans ^arr[i];
        std::cout<<ans<<'\n';
    }
    return ans;
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

    int uniq = find_uniq(arr, size);
    std::cout<<'\n'<<uniq<<'\n';

    return 0;
}