#include <iostream>
#include <vector>
using namespace std;

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector<int> ans;
    // cout<<nRows<<mCols<<endl;
    for (int i=0; i<mCols; i++)
    {
        if (i%2==0)
        {
            for(int j=0; j<nRows; j++)
            {
                // cout<<arr[j][i]<<" ";
                // cout<<i<<j<<"bruh"<<endl;
                ans.push_back(arr[j][i]);
            }
        }
        else if (i%2==1)
        {
            for(int j=nRows-1; j>=0; j--)
            {
                // cout<<i<<j<<"bruh"<<endl;
                // cout<<arr[j][i]<<" ";
                ans.push_back(arr[j][i]);
            }
        }
        // cout<<endl<<"wtf"<<endl;
        // why tf are we told to print if we have to return brug
    }
    return ans;
}