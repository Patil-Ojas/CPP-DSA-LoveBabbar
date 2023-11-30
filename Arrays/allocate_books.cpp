
#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int> arr, int n, long long int val)
{
    long long int c = 1;
    long long int curr = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        curr += arr[i];
        if (curr > val)
        {
            c++;
            curr = arr[i];
        }
    }
    if (c > n)
        return false;
    return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time)
{
    long long int h = 0, l = 0, mid, ans = -1;
    for (int i = 0; i < time.size(); i++)
    {
        if (l < time[i])
        {
            l = time[i];
        }
        h += time[i];
    }
    while (l <= h)
    {
        mid = l + (h - l) / 2;
        if (check(time, n, mid))
        {
            ans = mid;
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}