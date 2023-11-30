
#include <iostream>
using namespace std;

void printRowSums(int arr[][3], int m, int n)
{
    for (int i=0; i<m; i++)
    {
        int rs = 0;
        for (int j=0; j<n; j++)
        {
            rs = rs + arr[i][j];
        }
        cout<<rs<<endl;
    }
}

int main()
{
    int m, n;
    cin>>m>>n;
    int arr[m][3];

    for (int i=0; i<m; i++)
    {
        for (int j=0; j<3; j++)
        {
            cin>>arr[i][j];
        }
    }
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<3; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    printRowSums(arr, m, 3);
    return 0;
}