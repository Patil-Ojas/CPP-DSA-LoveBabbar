
#include <iostream>
using namespace std;

int max_sum_row(int arr[][3], int m, int n)
{
    int maxx = -9999;
    for (int i=0; i<m; i++)
    {
        int rs = 0;
        for (int j=0; j<n; j++)
        {
            rs = rs + arr[i][j];
        }
        maxx = max(rs, maxx);
    }
    return maxx;
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
    int amxx = max_sum_row(arr, m, 3);
    cout<<amxx;
    return 0;
}