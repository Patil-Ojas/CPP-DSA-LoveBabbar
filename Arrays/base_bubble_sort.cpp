
// Use case - when the size of vectpr/array is small

#include <iostream>
using namespace std;

void bubblesort3000(int arr[], int n)
{
    for (int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if (arr[j] < arr[i])
            {
                swap(arr[i], arr[j]);
            }
        }
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

    bubblesort3000(arr, n);

    for (int i=0; i<n; i++)
    {
        cout<<arr[i]<<' ';
    }
    return 0;
}