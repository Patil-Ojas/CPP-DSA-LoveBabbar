
#include <iostream>
#include <vector>
using namespace std;

//imperfect
// int find_pivot(vector<int> &arr, int size)
// {
//     int low = 0;
//     int high = size-1;
//     int mid = low + (high-low)/2;

//     while (low<=high)
//     {   
//         if (arr[mid] > arr[mid+1])
//         {
//             return mid+1;
//         }
//         else if (arr[mid] > arr[0])
//         {
//             low = mid;
//         }
//         else
//         {
//             high = mid; 
//         }
//         mid = low + (high-low)/2;
//     }
//     return -1;
// }

int find_pivot(vector<int>& arr, int n) {

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

int b_search(vector<int>& arr, int s, int e, int key) {

    int start = s;
    int end = e;

    int mid = start + (end-start)/2;

    while(start <= end) {

        if(arr[mid] == key) {
            return mid;
        }

        //go to right wala part
        if(key > arr[mid]) {
            start = mid + 1;
        }
        else{ //key < arr[mid]
            end = mid - 1;
        }

        mid = start + (end-start)/2;
    }
    
    return -1;
}

int search(vector<int>& arr, int n, int k)
{
    int pivot = find_pivot(arr, n);
    if( k >= arr[pivot] && k <= arr[n-1])
    {
        return b_search(arr, pivot, n-1, k);
    }
    else
    {
        return b_search(arr, 0, pivot - 1, k);
    }
}
