








// O(N)

// class Solution {
// public:
//     int peakIndexInMountainArray(vector<int>& arr) {
//         int len = arr.size();
//         for (int i=1; i<len-1; i++)
//         {
//             if ((arr[i-1] < arr[i]) and (arr[i] > arr[i+1]))
//             {
//                 return i;
//             }
//         }
//     return -1;
//     }
// };

// O(logn) but bad (mi first own solution 🥺)   

// class Solution {
// public:
//     int peakIndexInMountainArray(vector<int>& arr) {
        
//         int n = arr.size();
//         int low = 0;
//         int high = n-1;

//         int mid = low + (high-low)/2;

//         while (low<=high)
//         {
//             if ((arr[mid-1]<arr[mid]) and (arr[mid]>arr[mid+1]))
//             {
//                 return mid;
//             }
//             else if ((arr[mid-1]>arr[mid]) and (arr[mid]>arr[mid+1]))
//             {
//                 high = mid;
//             }
//             else if ((arr[mid-1]<arr[mid]) and (arr[mid]<arr[mid+1]))
//             {
//                 low = mid;
//             }
//             else
//             {
//                 return -1;
//             }
//             mid = low + (high-low)/2;
//         }
//         return 0;
//     }
// };




// O(logn)

// class Solution {
// public:
//     int peakIndexInMountainArray(vector<int>& arr) {
        
//         int n = arr.size();
//         int low = 0;
//         int high = n-1;

//         int mid = low + (high-low)/2;

//         while (low<high)
//         {
//             if (arr[mid] < arr[mid+1])
//             {
//                 low = mid + 1;
//             }
//             else
//             {
//                 high = mid;
//             }
//             mid = low + (high-low)/2;
//         }
//         return low;
//     }
// };