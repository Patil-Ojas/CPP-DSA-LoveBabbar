#include <iostream>
#include <vector>
#include <utility>

int firstoccr(std::vector<int> &arr, int n, int k)
{
    int first = -1;
    int low = 0;
    int high = n - 1;

    int mid = low + (high - low) / 2;

    while (low <= high)
    {
        if (arr[mid] == k)
        {
            first = mid;
            high = mid - 1;
        }
        else if (arr[mid] > k)
        {
            high = mid - 1;
        }
        else if (arr[mid] < k)
        {
            low = mid + 1;
        }
        mid = low + (high - low) / 2;
    }
    return first;
}

int lastoccr(std::vector<int> &arr, int n, int k)
{
    int last = -1;
    int low = 0;
    int high = n - 1;

    int mid = low + (high - low) / 2;

    while (low <= high)
    {
        if (arr[mid] == k)
        {
            last = mid;
            low = mid + 1;
        }
        else if (arr[mid] > k)
        {
            high = mid - 1;
        }
        else if (arr[mid] < k)
        {
            low = mid + 1;
        }
        mid = low + (high - low) / 2;
    }
    return last;
}

std::pair<int, int> firstAndLastPosition(std::vector<int> &arr, int n, int k)
{

    std::pair<int, int> ans;

    ans.first = firstoccr(arr, n, k);
    if (ans.first == -1)
    {
        ans.second = -1;
        return ans;
    }
    ans.second = lastoccr(arr, n, k);

    return ans;
}

int main()
{
    int n, k;

    // Input the size of the array
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    // Input the elements of the array
    std::vector<int> arr(n);
    std::cout << "Enter " << n << " elements of the array: ";
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }

    // Input the element to find
    std::cout << "Enter the element to find: ";
    std::cin >> k;

    // Find the first and last occurrence of the element
    std::pair<int, int> result = firstAndLastPosition(arr, n, k);

    // Display the result
    std::cout << "First occurrence: " << result.first << std::endl;
    std::cout << "Last occurrence: " << result.second << std::endl;

    return 0;
}








// alternate


// #include<bits/stdc++.h>

// pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
// {

//     int lb = lower_bound(arr.begin(), arr.end(), k) - arr.begin();

//     int ub = upper_bound(arr.begin(), arr.end(), k) - arr.begin();

//     if(lb == n || arr[lb] != k) return make_pair(-1,-1);

//     return make_pair(lb, ub-1);

// }