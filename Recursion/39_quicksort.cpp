#include <bits/stdc++.h> 
#include <vector>
using namespace std;


int partition(vector<int> &arr,int low,int high){
    int i=low,j=high;
    while(i<j){
        while(arr[i]<=arr[low]&&i<=high) i++;
        while(arr[j]>arr[low]&&j>=low) j--;
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}

void solver3000(vector<int> &arr, int s, int e)
{
    if (s>=e)
        return;

    int part = partition(arr, s, e);
    // left part
    solver3000(arr, s, part-1);
    // right part
    solver3000(arr, part+1, e);
}

vector<int> quickSort(vector<int> arr)
{
    solver3000(arr, 0, arr.size()-1);
    return arr;
}
