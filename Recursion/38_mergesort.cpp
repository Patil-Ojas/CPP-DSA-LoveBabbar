#include <vector>
using namespace std;



void Merge(vector <int> &a, int low, int high, int mid)
{
    // We have low to mid and mid+1 to high already sorted.
    int i, j, k, temp[high-low+1];
    i = low;
    k = 0;
    j = mid + 1;
 
    // Merge the two parts into temp[].
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            temp[k] = a[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = a[j];
            k++;
            j++;
        }
    }
 
    // Insert all the remaining values from i to mid into temp[].
    while (i <= mid)
    {
        temp[k] = a[i];
        k++;
        i++;
    }
 
    // Insert all the remaining values from j to high into temp[].
    while (j <= high)
    {
        temp[k] = a[j];
        k++;
        j++;
    }
 
    // Assign sorted data stored in temp[] to a[].
    for (i = low; i <= high; i++)
    {
        a[i] = temp[i-low];
    }
}
 
// A function to split array into two parts.
void MergeSort(vector<int> &a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        // Split the data into two half.
        MergeSort(a, low, mid);
        MergeSort(a, mid+1, high);
 
        // Merge them to get sorted output.
        Merge(a, low, high, mid);
    }
}

void mergeSort(vector < int > & arr, int n) {
    MergeSort(arr, 0, n-1);
}