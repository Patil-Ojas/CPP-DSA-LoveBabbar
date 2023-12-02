
// given in input an sorted and rotated array, find its input
// I/P: [6, 7, 9, 1, 2, 3, 4, 5]
// I/P: [4, 5, 6, 7, 9, 1, 2, 3]
// O/P: either 9 or 1 can be ans, but here  we take 1


//good shit bois we hav ehope
// well tried

#include <iostream>

// imperfect
// int find_pivot(int arr[], int size)
// {
//     int l=0;
//     int h=size-1;
//     int mid = l + (h - l)/2;

//     while (l<=h)
//     {
//         if (arr[mid] > arr[mid+1])
//         {
//             return mid+1;
//         }
//         else if (arr[mid] > arr[0])
//         {
//             l = mid + 1;
//         }
//         else
//         {
//             h = mid - 1;
//         }
//         mid = l + (h-l)/2;
//     }
//     return -1;
// }

#include<iostream> 
using namespace std;

int find_pivot(int arr[], int n) {

    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s<e) {

        if(arr[mid] >= arr[0])
        {
            s = mid+1;
        }
        else{
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
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

    int pivot = find_pivot(arr, size);
    std::cout<<"pivot is: "<<pivot;
    return 0;
}