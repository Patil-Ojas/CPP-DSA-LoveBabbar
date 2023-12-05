
// Use case - adaptable (works nice on partially sorted arrays), stable algo (ensures relative order or equal elements)

#include <iostream>
using namespace std;

void insertionsort3000(int arr[], int n)
{
    int j, temp;

    for (int i=0; i<n; i++)
    {
        temp = arr[i];
        j = i-1;

        while (j>=0 and arr[j]>temp)
        {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1]=temp;
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];

    for (int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    insertionsort3000(arr, n);

    for (int i=0; i<n; i++)
    {
        cout<<arr[i]<<' ';
    }
    return 0;
}