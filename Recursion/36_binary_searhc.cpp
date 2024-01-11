//  i hate my life
#include <vector>
using namespace std;


int b_search(vector<int> nums, int l, int h, int k)
{
    int mid = l + (h-l)/2;

    while (l<=h)
    {
        if (nums[mid] == k)
            return mid;
        else if (nums[mid] < k)
        {
            l = mid + 1;
        }
        else if (nums[mid] >  k)
        {
            h = mid - 1;
        }
        else
        {
            return -1;
        }
        mid = l + (h-l)/2;
    }
    return -1;
}

// int b_search(vector<int> &nums, int l, int h, int k)
// {
//     if (l>h)
//         return -1;
//     else
//     {
//         int mid = l + (h-l)/2;

//         if (nums[mid]==k)
//         {
//             return mid;
//         }
//         else if (nums[mid] < k)
//         {
//             return b_search(nums, mid+1, h, k);
//         }
//         else
//         {
//             return b_search(nums, l, mid-1, k);
//         }
//     }
// }

int search(vector<int> &nums, int target) {
    // Write your code here.
    int low = 0;
    int high = nums.size()-1;
    // cout<<high;

    int ans = b_search(nums, low, high, target);
    // cout<<"aaaa: "<<ans<<endl;

    if (ans==-1)
        return -1;
    else
        return ans;
}